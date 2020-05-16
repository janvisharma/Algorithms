#include <iostream>
using namespace std;
/*
    Quick Sort Analysis
    Preferred for large inputs
    Average Time Complexity is O(nlogn) and the constant factors in the O notation are quite small
    Worst Case can be O(n^2) -> happens due to unbalanced partition -> array already sorted 
    But in practice the probability of worse case is quite small

    Partition sub routine takes O(n) linear time
    QuickSort makes 2 calls
    If we consider balanced partition then the recursion becomes:
        T(n) = 2T(n/2) + O(n) which is O(nlogn) by Master Theorem
*/
int Partition(int A[], int p, int r){
    int x = A[r]; // we always choose the last element as the pivot
    int i = p - 1;

    int j,temp;
    for(j=p;j<r;j++){
        temp = 0;
        if(A[j]<=x){
            // if the element at A[j] is less than the pivot then it belongs to the left sub array
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;            
        }
    }

    /* when for loop is terminated we have successfully made 2 sub arrays 
    The one on the left of pivot: all elements smaller than or equal to pivot
    The one on the right of pivot: all elements greater than pivot

    Then we insert the pivot in its correct position i.e. i+1 
    */
    temp = 0;
    temp = A[r];
    A[r] = A[i+1];
    A[i+1] = temp;    
    return (i+1);
}


void QuickSort(int A[], int p, int r){
    if(p<r){
        int q = Partition(A,p,r);
        /*
            At this point the element A[q] is at its correct position
            So we recursively call QuickSort on the left and right sub arrays
        */
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main(){
    cout<<"Enter number of elements: ";
    int n,i;
    cin>>n;
    int A[n];
    cout<<"Enter elements of array: ";
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    QuickSort(A,0,n-1);

    cout<<"Sorted Array is ";
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}