#include<iostream>
using namespace std;
/*
    Time Complexity of Insertion Sort 
    Using Loop rule: 
    Outer for loop runs n times*{Inner for loop runs O(n) times}
    Rest all statements are O(1)
    Thus complexity of Insertion Sort is O(n^2) Quadratic Time
*/
void InsertionSort(int ar[], int n){
    int small, pos,i,k,temp; 

    for(i=0;i<n;i++){ 
        small = ar[i];
        pos = i;       

        for(k=i+1;k<n;k++){
            if(ar[k]<small){
                small = ar[k];
                pos = k;
            }
        }
        temp = ar[i];
        ar[i] = small;
        ar[pos] = temp;

        cout<<"Iteration "<<i+1<<": ";
        for(int k=0;k<n;k++){
        cout<<ar[k]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    int i,ar[size];
    cout<<"Enter elements of array: "<<endl;
    for(i=0;i<size;i++){
        cin>>ar[i];
    }
    InsertionSort(ar,size);

    cout<<"Sorted array is: "<<endl;
    for(i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}