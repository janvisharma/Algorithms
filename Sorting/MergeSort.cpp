#include<iostream>
using namespace std;


void Merge(int A[], int start, int mid, int end){

    int n1 = mid - start + 1;
    int n2 = end - mid;
    cout<<"Merge Called n1 is "<<n1<<" n2 is "<<n2<<endl;

    int L[n1], R[n2];

    int i, j, k=0;

    for(i=0;i<n1;i++){
        L[i] = A[start+i];
    }

    for(j=0;j<n2;j++){
        R[j]=A[mid+1+j];
    }
    cout<<"Left Array: ";

    for(int m=0;m<n1;m++){
        cout<<L[m]<<" ";
    }
    cout<<endl<<"Right Array: ";
    for(int m=0;m<n2;m++){
        cout<<R[m]<<" ";
    }
    cout<<endl;

    i = 0; j = 0, k=start;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
            k++;
        }
        else {
            A[k] = R[j];
            j++;
            k++;
        }
    }

    while (i<n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
    cout<<"A right now: ";
    for(int m=0;m<n1+n2;m++){
        cout<<A[m]<<" ";
    }
    cout<<endl;
}

void MergeSort(int A[],int start, int end){
  
    if(start<end){
        int mid = start+(end-start)/2;
       
        MergeSort(A,start,mid);
        MergeSort(A,mid+1,end);

        Merge(A,start,mid,end);
    }
}

int main() {

    cout<<"Enter number of elements in array: ";
    int n;
    cin>>n;
    cout<<endl<<"Enter ele of array: ";

    int i,A[n];

    for(i=0;i<n;i++){
        cin>>A[i];
    }

    MergeSort(A,0,n-1);

    cout<<"The sorted array is "<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}