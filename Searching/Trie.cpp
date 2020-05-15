// Efficient information reTRIEval data structure
// complexity O(n) where n is the length of the string/word you are looking for 

#include <iostream>
#include <string.h>
using namespace std;

struct TRIEnode {
    TRIEnode *childNode[26] = {};
    bool isEndOfWord = false;
};
void InsertInTrie(TRIEnode *root, string key){
    TRIEnode *x = root;
    int i, index;
    for(i=0;i<key.length();i++){
        index = key[i] - 'a'; // calculating ASCII code to fit into 0-25 
        if(x->childNode[index]==nullptr){
            TRIEnode *newNode = new TRIEnode;
            x->childNode[index] = newNode;
        }
        x = x->childNode[index];
    }
    x->isEndOfWord = true;
}
bool searchInTRIE(TRIEnode *root, string key){
    TRIEnode *x = root;
    int i, index;
    for(i=0;i<key.length();i++){
        index = key[i] - 'a'; 
        if(x->childNode[index]==nullptr){
            return false;
        }
        else
        {
            x = x->childNode[index];
        }
    }
    return (x!=nullptr && x->isEndOfWord);
}

int main() {
    TRIEnode *root = new TRIEnode; // root pointer pointing to a null node of type TRIEnode
    string keys[] = {"janvi","hazel","seyounga","utkarsh","hello"};
    int sizeOfKeys = 5;

    int i;
    for(i=0;i<sizeOfKeys;i++){
        InsertInTrie(root,keys[i]);
    }

    cout<<searchInTRIE(root,"janvi")<<endl;
    cout<<searchInTRIE(root,"hazel")<<endl;

}