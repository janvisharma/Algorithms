#include<iostream>
using namespace std;

struct list {
    int len;
    int elementArray[10];
};

int linearSearch(int ar[], int len, int key) {
    int i,pos=-1;
    /*
        Time Complexity:
            Loop rule: no. of iterations*code inside
            len*O(1) = O(n) where n is the length 
            Linear time 
            In worst case you need to loop through each element - either the key is the 
            last ele or its not found
    
    */
    for(i=0;i<len;i++){
        if(key==ar[i]){
            pos = i;
            break;
        }
    }
    return pos;
}


bool insertKeyInList(int ar[], int &key,int n){
    if(n==10){
        // the max length of list we have defined is 10
        cout<<"Overflow!";
        return false;
    }
    else
    {   
        /*
            Time Complexity: 
                This function inserts a new element at the head of the list
                All existing elements are moved ahead by one index
                This would require "n" steps where n is the number of elements
                Thus the time complexity is O(n) -> linear time
        */
        for(int i=n;i>0;i--){
            ar[i] = ar[i-1];
        }
        cout<<"\n";
        return true;
    }
}
void deleteElement(int ar[], int len, int pos){
    /*
        Deleting elements given a key
        So first we need to search for the position: done with linear search O(n)

        Now we need to move the elements from pos+1 a step backwards
        considering worst case
        this would take O(n) steps 
        Linear time 
    */

    for(int i=pos;i<len-1;i++){
        ar[i] = ar[i+1];
    }
    
    return;
}


int main() {
    list L;

    L.len = 0; // initializing the list O(1) time
    L.elementArray[10] = {0};

    int n;
    cout<<"Enter the no. of ele you want in your list ";
    cin>>n;
    L.len = n;

    cout<<"Enter your elements: ";
    for(int i=0;i<n;i++){
        cin>>L.elementArray[i];
    }
    cout<<"Your list is ";
    for(int k=0;k<n;k++){
        cout<<L.elementArray[k]<<" ";
    }

    int ch;

    while (ch!=-1)
    {
    cout<<"\n";
    cout<<"1. Search for an element"<<endl;
    cout<<"2. Insert an element"<<endl;
    cout<<"3. Delete an element"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch){
        case 1: {
                    cout<<endl<<"Enter ele you wish to look for: ";
                    int key;
                    cin>>key;
                    
                    int pos = linearSearch(L.elementArray, n, key);
                    if(pos!=-1){
                    cout<<"Found at pos "<<pos+1;
                    }
                    else
                    {
                        cout<<"Not found!";
                    }
                }   
                break;
        case 2: {
                    cout<<endl<<"Enter ele you wish to insert: ";
                    bool val;
                    int insertKey;
                    cin>>insertKey;
                    val = insertKeyInList(L.elementArray, insertKey, L.len);
                    if(val){
                        L.len++;
                        L.elementArray[0] = insertKey;
                        cout<<"The new list is ";
                        for(int k=0;k<L.len;k++){   
                            cout<<L.elementArray[k]<<" ";
                        }
                    }
                }
                break;
        case 3: {
                    cout<<"Enter element you wish to delete: "; // need to search for key first
                    int deleteKey;
                    cin>>deleteKey;
                    int dpos = linearSearch(L.elementArray, L.len, deleteKey);
                    if(dpos!=-1){
                        deleteElement(L.elementArray,L.len,dpos);
                        L.len--;
                        cout<<"After deletion : ";
                        for(int k=0;k<L.len;k++){
                            cout<<L.elementArray[k]<<" ";
                        }
                    }

                    else
                    {
                        cout<<"Element not in array! Cannot delete ~"<<endl;                
                    }
                }
                break;
        case 4: exit(0);
    }
    }

    return 0;
}