#include<iostream>
using namespace std;

struct list{
    int len=0;
    int head=0;
    int tail=0;
    int elementArray[10];
};
/*
    Insertion in Queue can only occur at one end i.e. the tail
    A queue maintains FIFO
    Time complexity in case of array insertion would be O(1)
*/
void InsertInQueue(list &L, int key){
    if(L.len==10){
        cout<<"Overflow!";
        return;
    }
    else
    {   
        L.len++;
        L.elementArray[L.tail%10] = key;
        L.tail = (L.tail+1)%10; // head represents the next empty slot
    }
    
}
/*
    The first element to come in is the first one to be deleted
    Deletion in case of an array takes O(1)
    The reason for using mod: circular queue so that the queue
    wraps around
*/
void DeleteInQueue(list &L){
    if(L.len == 0){
        cout<<"Underflow!";
        return;
    }
    else
    {
        L.head = (L.head+1)%10;
        L.len--;
    }
}

void DisplayQueue(list L){
    if(L.len==0){
        cout<<"No elements in queue!"<<endl;
        return;
    }
    else
    {
        for(int i = L.head;i<L.tail;i++){
        cout<<L.elementArray[i]<<" -> "; }
    }
}
int main(){
    list L;
    cout<<"Queue implementation using an array! "<<endl;
    int ch = -1;

    while(ch!=0){
        cout<<endl<<"1. Insert an element"<<endl;;
        cout<<"2. Delete an element"<<endl;
        cout<<"3. Display the queue"<<endl;
        cout<<"4. Exit"<<endl;

        cin>>ch;

        switch (ch)
        {
        case 1: {
            cout<<"Enter the element you wish to insert in the queue: ";
            int key;
            cin>>key;
            InsertInQueue(L,key);
            break;
        }
        case 2: {
            DeleteInQueue(L);
            break;
        }
        case 3: {
            cout<<"The current queue is: "<<endl;
            DisplayQueue(L);
            break;
        }
        case 4: {exit(0);}
        }
    }
}