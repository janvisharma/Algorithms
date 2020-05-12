struct BinaryTree{
    BinaryTree *parent;
    BinaryTree *leftChild;
    BinaryTree *rightChild;
    int value;
};
void InsertInBinaryTree(BinaryTree *&root, int val){
    if(root==nullptr){
        // first node to be encountered
        BinaryTree *incomingNode = new BinaryTree;
        incomingNode->rightChild=nullptr;
        incomingNode->leftChild=nullptr;
        incomingNode->parent=nullptr;
        incomingNode->value = val;
        root = incomingNode;
    }
    else{
        BinaryTree *incomingNode = new BinaryTree;
        incomingNode->rightChild=nullptr;
        incomingNode->leftChild=nullptr;
        incomingNode->parent=nullptr;
        incomingNode->value = val;
        
        BinaryTree *x,*p;
        x = root;
        p = nullptr;
        while(x!=nullptr){
            if(incomingNode->value<x->value){
                p = x;
                x = x->leftChild;
            }
            else
            {
                if(incomingNode->value>x->value){
                    p = x;
                    x = x->rightChild;
                }
            }
        }
        
        incomingNode->parent = p;
        if(p->value<incomingNode->value){
            p->rightChild = incomingNode;
        }
        else{
            p->leftChild = incomingNode;
        }
    }
}

void InorderTraverse(BinaryTree *root){
    if(root==nullptr){
        return;
    }
    else
    {
        InorderTraverse(root->leftChild);
        cout<<root->value<<" ";
        InorderTraverse(root->rightChild);
    }
}
#include<iostream>
using namespace std;

int main(){
    BinaryTree *root = nullptr;

    InsertInBinaryTree(root,10);
    InsertInBinaryTree(root,12);
    InsertInBinaryTree(root,18);
    
    InorderTraverse(root);

}