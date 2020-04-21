#include<iostream>
using namespace std;
/*
    Interpolation Search tries to better Binary Search
    Instead of going to the middle element, it will try to go to a 
    possible vicinity of the 'key' and start searching
    Assumption: the numbers are ordered and uniformly distributed

    Time Complexity is O(loglogn)
*/
void InterpolationSearch(int Ar[], int size, int key){
    int high = size-1, low = 0, pos =-1, sIndex;
    int numOfComparisons = 0;
    while(low<=high && pos==-1 && key>=low && key<=high){
        numOfComparisons++;
        sIndex = low + ( ((high-low)/(Ar[high]-Ar[low]))*(key-Ar[low]));
        if(low==high){
            if(key==Ar[low]){
                cout<<"Found at position: "<<low+1<<endl;
                pos = 1;
                break;
            } 
        }
        if(Ar[sIndex]==key){
            cout<<"Found at position: "<<sIndex+1<<endl;
            pos = 1;
            break;
        }
        else
        {
            if(Ar[sIndex]>key){
                high = sIndex -1;
            }
            if(Ar[sIndex]<key){
                low = sIndex + 1;
            }
        }
    }
    cout<<"Total no. of comparisons made: "<<numOfComparisons;
}
int main(){
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

    InterpolationSearch(ar, size, key);

}