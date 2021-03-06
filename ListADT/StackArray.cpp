#include<iostream>
using namespace std;

struct list {
    int len = 0;
    int top = 0;
    int elementArray[10]; // 10 is the max size
};
/*
    Stack ADT implemented using an array
    A stack follows LIFO 
    Deletion and Insertion can only occur at one side of the stack i.e. is top
*/

/*
    Time Complexity of Insertion 
    O(1) constant time
    because we can directly assign the values given an array address
*/
void InsertInStack(list &L, int key){
    if(L.len==10){
        cout<<"Overflow!"<<endl;
        return;
    }
    else
    {
        // here top stores the next available space in stack
        L.elementArray[L.top] = key;
        L.top++;
        L.len++;
    }
}
/*
    Time Complexity of Display
    O(n) -> we need to loop through all elements in the array
*/
void DisplayStackElements(list L){
    int size = L.len;
    for(int i = 0;i<size;i++){
        cout<<L.elementArray[i]<<" -> ";
    }
}
/*
    Time Complexity of Delete
    O(1) because we just need to decrement the top and the length
*/
void DeleteElementInStack(list &L){
    if(L.len == 0){
        cout<<"Underflow!";
        return;
    }
    else
    {
        L.top--;
        L.len--;
    }
}
int main(){
    list L;
    cout<<"Stack Implementation of a List!"<<endl;

    int ch = -1;
    while(ch!=0){
         cout<<endl;
         cout<<"1. Insert an element"<<endl;
         cout<<"2. Delete an element"<<endl;
         cout<<"3. Display the stack"<<endl;
         cout<<"4. Exit"<<endl;

         cin>>ch;
         switch (ch)
         {
             case 1: { 
                    cout<<"Enter the element you wish to insert: "; 
                    int key;
                    cin>>key;
                    InsertInStack(L,key);
                    break;
             }
             case 2: {
                    cout<<"Deleting the top element in stack "<<endl;
                    DeleteElementInStack(L);
                    break;
             }
             case 3: {
                    cout<<"The current stack contains: "<<endl;
                    DisplayStackElements(L);
                    break;
             }
             case 4: { exit(0); }
                    
         }
    }

}