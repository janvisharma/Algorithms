#include<iostream>
using namespace std;

/*
    Heap Sort: Combines the good things about Insertion sort and Merge Sort
    Complexity: O(nlogn) like Merge Sort & it sorts in place like Insertion Sort
*/
int BinarySearch(int ar[], int key, int size){
    int mid, first=0, last=size-1;
    int pos = -1;
    while(last>=first && (pos == -1)){
        mid = (first+last)/2;
        if(key>ar[mid]){
            first = mid+1;
        }
        if(key<ar[mid]){
            last = mid - 1;
        }
        if(key==ar[mid]){
            pos = mid;
            return pos;
        }
    }
}
void max_heapify(int Ar[], int key, int size){
    int posKey = BinarySearch(Ar, key, size);
    int left = 2*posKey;
    int right = 2*posKey+1;
    int largest=posKey;
    if(left<=size-1 && Ar[left]>Ar[posKey]){
        largest = left;
    }
    if(right<=size-1 && Ar[right]>Ar[largest]){
        largest = right;
    }
    if(largest!=posKey){
        int temp = Ar[posKey];
        Ar[posKey] = Ar[largest];
        Ar[largest] = temp;

        max_heapify(Ar,Ar[largest],size);
    }

}
void buildMaxHeap(int Ar[], int size){
    int mid = size/2,i;
    for(i=mid-1;i>=0;i--){
        max_heapify(Ar, Ar[i],size);
    }
}

void HeapSort(int Ar[], int size){
    buildMaxHeap(Ar, size);
    int i, max=0,temp,n = size;
    for(i=0;i<size;i++){
        max = Ar[0];
        temp = max;
        Ar[0] = Ar[size-1];
        Ar[size-1] = max;
        size = size - 1;
        buildMaxHeap(Ar,size);
    }
    for(i=0;i<n;i++){
        cout<<Ar[i]<<" ";
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int Ar[size];
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>Ar[i];
    }

    HeapSort(Ar,size);
}