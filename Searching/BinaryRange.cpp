#include<iostream>
using namespace std;

int FindPosInArray(int A[], int key, int n){
    // O(logn)
    int first = 0, last = n-1,mid,pos=-1;
    while(first<=last && pos==-1){
        mid = (first+last)/2;
        if(A[mid]==key){
            return mid;
        }
        if(A[mid]>key){
            last = mid - 1;
        }
        if(A[mid]<key){
            first = mid + 1;
        }
    }
}
void BinaryRange( int s, int e, int A[], int n){
    int first = 0, last = n-1,mid;
    int posS = FindPosInArray(A, s, n);
    int posE = FindPosInArray(A, e, n);

    for(int i=posS; i<posE+1;i++){
        // depends on the range between the numbers you input
        // worse case = O(n)
        cout<<A[i]<<" ";
    }
}
int main(){
    int start, end, n;
    cout<<"Enter size of an array: ";
    cin>>n;
    int A[n];

    cout<<"Enter elements of the array (sorted): ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    cout<<"Enter range of nos. you wish to output: ";
    cin>>start>>end;
    BinaryRange(start,end,A,n);

}