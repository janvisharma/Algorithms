#include<iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

/*
    Time Complexity: Insertion at beginning
    Since we only change a few pointers
    Each statement takes O(1) time
    Thus insertNewNode is O(1) constant time function
*/

void insertNewNode(node *&start, int value){
    if(start==NULL) {
        // list is empty 
        node *newNode = new node; 
        newNode->value = value; 
        newNode->next = NULL;
        start = newNode; 
    }
    else
    {   
        // non empty list 
        node *newNode = new node; 
        newNode->value = value; 
        newNode->next = start; 
        start = newNode;
    }
}
/*
    Time Complexity of Deletion at beginning
    Since this function only requires a few pointer changes 
    Each statement takes constant time
    Thus the complexity is O(1)
*/
void deleteFirstNode(node *&start){
    if(start==NULL){
        cout<<"Underflow! "; // list is empty cannot delete anymore
    }
    else {
        node *temp; 
        temp = start; 
        start = temp->next; 
        delete temp; 
        cout<<"Deletion successful! ";
    }
}

void displayLinkedList(node * start){
    node *p;
    p = start;
    if(start==NULL){
        cout<<"No elements in list! "<<endl;
    }
    else
    {
        while(p!=NULL){
        cout<<p->value<<"-> ";
        p = p->next;
        }
    }
}

int main(){
    node *start;
    start = NULL;
    int ch=0;

    while(ch!=-1){
        cout<<endl<<"Linked List Menu "<<endl;
        cout<<"1. Insert new node "<<endl;
        cout<<"2. Delete a node"<<endl;
        cout<<"3. Display list"<<endl;
        cout<<"4. Exit"<<endl;

        cin>>ch;
        switch(ch){
            case 1: {
                cout<<"Enter value to insert: ";
                int val;
                cin>>val;
                insertNewNode(start, val);  
                break;
            }
            case 2: {
                cout<<endl<<"Deletion occurs at the beginning "<<endl;
                deleteFirstNode(start);
                break;
            }
            case 3: {
                cout<<"The current list is: "<<endl;
                displayLinkedList(start);
                break;
            }
            case 4: {
                exit(0);
            }

        }
    }



    return 0;
}