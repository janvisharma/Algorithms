#include<iostream>
using namespace std;

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
BinaryTree *minValueSucc(BinaryTree *root){
    BinaryTree *min = nullptr;
    if(root==nullptr){
        min = root;
        return min;
    }
    else{
        BinaryTree *min = root;
        while(min!=nullptr){
            min = min->rightChild;
        }
        return min;
    }
}
void DeleteInBinaryTree(BinaryTree *root, int key){
    if(root==nullptr){
        cout<<"empty tree!";
        return;
    }
    else{
        // first we need to find the node in the tree
        if(SearchInBinaryTree(root,key)==true){
            BinaryTree *x,*p;
            x = root;
            while(x!=nullptr){
                if(x->value==key){
                    p = x->parent;
                }
                else{
                    if(x->value>key){
                        x = x->leftChild;
                    }
                    else
                    {
                        x = x->rightChild;
                    }
                }
            }
            if(x->leftChild==nullptr && x->rightChild==nullptr){
                // leaf node, can simply delete it
                if(x->value<p->value){
                    p->rightChild = nullptr;
                }
                else
                {
                    p->leftChild = nullptr;
                }
                delete x; return;
            }
            // node to be deleted has one child 
            if(x->leftChild!=nullptr and x->rightChild==nullptr){
                if(x->value>p->value){
                    // x.value > parent.value then x was the right child 
                    p->rightChild = x->leftChild;
                }
                else
                {
                    // x.val < parent.val then x was left child
                    p->leftChild = x->leftChild;
                    
                }
                delete x; return;
            }
            if(x->leftChild==nullptr and x->rightChild!=nullptr){
                if(x->value>p->value){
                    // x.value > parent.value then x was the right child 
                    p->rightChild = x->rightChild;
                }
                else
                {
                    // x.val < parent.val then x was left child
                    p->leftChild = x->rightChild;
                    
                }
                delete x; return;
            }
            // Case 3: x has 2 children, we need to find the min val successor 
            BinaryTree *minValue;
            minValue = minValueSucc(x->rightChild);
            x->value = minValue->value;
            DeleteInBinaryTree(x->rightChild,minValue->value);
            
        }
        else
        {
            cout<<"Element not in BST! Cannot Delete!";
            return;
        }
        
        

    }

}
bool SearchInBinaryTree(BinaryTree *root, int key){
    if(root==nullptr){
        cout<<"Binary Tree is empty! ";
        return false;
    }
    else{
        BinaryTree *x;
        x = root;
        while(x!=nullptr){
            if(x->value==key){
                cout<<"Found!";
                return true;
            }
            else{
                if(x->value>key){
                    x = x->leftChild;
                }
                else
                {
                    x = x->rightChild;
                }
                
            }
        }
        cout<<"Not found!";
        return false;
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

int main(){
    BinaryTree *root = nullptr;

    InsertInBinaryTree(root,10);
    InsertInBinaryTree(root,12);
    InsertInBinaryTree(root,18);

    InorderTraverse(root);

}