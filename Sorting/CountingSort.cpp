#include <iostream>
using namespace std;

void CountingSort(int A[], int n){
    cout<<"i am in";
    int C[6];
    int B[n];
    int i;
    for(i=0;i<n;i++){
        cout<<"fault 1";
        C[A[i]] = C[A[i]] + 1;
    }
    for(i=1;i<6;i++){
        cout<<"fault 2";
        C[i] = C[i] + C[i-1];
    }
    for(i=n-1;i>=0;i--){
        cout<<"fault 3";
        B[C[A[i]]] = A[i];
    }
    for(i=0;i<n;i++){
        cout<<"fault 4";
        A[i] = B[i];
    }
}


int main(){
    cout<<"Enter number of elements: ";
    int n,i;
    cin>>n;
    int A[n];
    cout<<"Enter elements of array: ";
    for(i=0;i<n;i++){
        cout<<"hello"<<i<<" ";
        cin>>A[i];
    }
    cout<<"hello";
    CountingSort(A,n);
    cout<<"Sorted array is ";
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}