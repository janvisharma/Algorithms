#include<iostream>
using namespace std;

int main() {
    int i,j, key, A[5];
    cout<<"Enter elements to be sorted";
    for(i=0;i<5;i++){
        cin>>A[i];
    }

    for(i=1;i<=5;i++){
        key = A[i];
        j = i-1;

        while( j>=0 && A[j]>key) {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;

        cout<<"Iteration "<<i<<endl;
        for(int m =0;m<5;m++){
        cout<<A[m]<<" ";
        }
        cout<<endl;

    }

    cout<<"The sorted array is ";
    for(i=0;i<5;i++){
        cout<<A[i]<<" ";
    }



}