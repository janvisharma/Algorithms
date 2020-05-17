#include <iostream>
using namespace std;
/*
    Sorting in Linear Time!
    (1) The lower bound of omega(nlogn) does not hold in this case
    because we are not using the comparison model
    (2) Needs to be modified to handle negative numbers 

    Idea: We count the number of elements that are less than or equal to 
    a particular number in A (input) to determine its position in the sorted array

    Complexity = O(n+k) where k is (max number + 1)
    If k = O(n) then the complexity can be reduced to O(n)
*/
void CountingSort(int A[], int n, int k){
    int C[k] = {0}; // don't forget to initialize with all 0s!
    int B[n] = {0};
    int i;

    for(i=0;i<n;i++){
        C[A[i]] = C[A[i]] + 1; // counting how many occurences of A[i] are there in input
    }
    
    for(i=1;i<k;i++){
        C[i] = C[i] + C[i-1]; // cumulative frequency
    }
    
    for(i=n-1;i>=0;i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
    // output stored in B[]
    for(i=0;i<n;i++){
        cout<<B[i]<<" "; 
    }
    return;
}

int main(){
    cout<<"Enter number of elements: ";
    int n,i;
    cin>>n;
    int A[n];
    cout<<"Enter range of elements you want to sort (0 to k): ";
    int range;
    cin>>range;
    cout<<"Enter elements of array bt 0 to "<<range<<" : ";
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    
    CountingSort(A,n,range+1);
    
    return 0;
}