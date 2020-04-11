#include<iostream>
using namespace std;

/*
    Time Complexity Analysis
    The first for loop, loops through each element in the array 
    Thus the upper bound (worst case) is O(n) where n is the 
    size of the array

    The rest of the statements execute O(1)
    Thus the complexity of Linear Search is O(n)
*/

void LinearSearch(int ar[], int key, int size){
    int i,pos=-1;
    for(i=0;i<size;i++){
        if(ar[i]==key){
            pos = i;
            break;
        }
    }
    if(pos!=-1){
        cout<<"Found at position: "<<i+1;
    }
    else
    {
        cout<<"Not found";
    }
    
}

int main() {
    cout<<"Enter size of array: ";
    int size;
    cin>>size;

    int i,ar[size];

    for(i=0;i<size;i++){
        cin>>ar[i];
    }
    cout<<"Enter Element to search for: ";
    int key;
    cin>>key;

    LinearSearch(ar, key, size);
    return 0;
}