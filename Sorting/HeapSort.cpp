#include<iostream>
using namespace std;

/*
    Heap Sort: Combines the good things about Selection sort and Merge Sort
    Complexity: O(nlogn)
    We acknowledge the fact that we are performing redundant comparisons in Selection
    sort, so to better our algorithm we use the idea of Merge Sort + Selection Sort -> Heap Sort
*/

/*
    Linear Search to find an element in the Heap
    O(n) time
*/
int LinearSearch(int Ar[], int k, int n){
    int pos=-1,i;
    for(i=0;i<n;i++){
        if(Ar[i]==k){
            return i;
        }
    }
    return 0;
}

/*
    Max_Heapify: O(h) time
    O(logn) where n = heapsize - 1
*/
void max_heapify(int Ar[], int key, int size){
    int posKey = LinearSearch(Ar, key, size);

    int left = 2*posKey+1;
    int right = 2*posKey+2;
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
/*
    Building a Max Heap
    O(n) linear time
*/
void buildMaxHeap(int Ar[], int size){
    int mid = size/2,i;
    for(i=mid;i>=0;i--){
        max_heapify(Ar, Ar[i],size);
    }
}
/*
    Heap Sort
    for loop: n*logn
    O(nlogn) time
*/
void HeapSort(int Ar[], int size){
    buildMaxHeap(Ar, size);
    int i, max=0,temp,n = size;
    for(i=0;i<n;i++){
        max = Ar[0];
        temp = max;
        Ar[0] = Ar[size-1];
        Ar[size-1] = max;
        size = size - 1;
        max_heapify(Ar,Ar[0],size);
    }
    cout<<"\n";
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
