#include<iostream>
using namespace std;

/*
    Time Complexity Analysis
    The while loop helps cut the problem size by 1/2 
    We can write this in a recurrence form as: 
        T(n) = T(n/2) + O(1)
    Where T(n) -> time needed to search in an array of n elements
          T(n/2) -> time needed to search in an array of n/2 elements
          O(1) -> some constant time needed for comparisons
    On solving this recurrence we get:
        T(n) = O(logn)
    This is better than linear search but the condition for binary search
    is that the elements must be sorted
*/

void BinarySearch(int ar[], int key, int size){
    int mid, first=0, last=size;
    int pos = -1;
    while(last>=first && (pos == -1)){
        mid = (first+last)/2;
        if(key==ar[mid]){
            pos = mid;
        }
        if(key>ar[mid]){
            first = mid+1;
        }
        if(key<ar[mid]){
            last = mid - 1;
        }
    }
    if(pos!=-1){
        cout<<"Found at position: "<<pos+1;
    }
    else
    {
        cout<<"Not found! ";
    }
    
}

int main() {
    cout<<"Enter size of array: ";
    int size;
    cin>>size;

    int i,ar[size];
    cout<<"Enter elements of array in sorted order: ";
    for(i=0;i<size;i++){
        cin>>ar[i];
    }
    cout<<"Enter Element to search for: ";
    int key;
    cin>>key;

    BinarySearch(ar,key,size);
    return 0;
}