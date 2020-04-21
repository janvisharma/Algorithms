#include<iostream>
#include<math.h>
using namespace std;

/*
    Square root search - best case of Jump Search
    Consider an array containing n elements
    choose a k<n, the best choice of k = (n)^1/2

    Instead of performing a linear search, jump search aims to 
    reduce the number of ele-ele comparisons made by "jumping"
    to an appropriate interval

    once you have decided a value for 'k'
    we will now examine the entries at Ar[k], Ar[2k], Ar[3k].... Ar[ik]
    if key<Ar[ik], you can run a linear search between: 
        Ar[(i-1)k+1] and Ar[ik-1]
    
    The number of comparisons made to find an interval in the worst case: floor(n/k)
    Then we need to make at least (k-1) comparisons
    Total number of comparisons: floor(n/k) + k - 1

    Worst case time complexity is: O(n^0.5) which is better than O(n) linear time!
    
    Important: This only works for sorted lists 
*/

int main(){
    int size, key, ctr = 1, numOfComparisons = 0,found = -1;
    cout<<"Enter size of your array: ";
    cin>>size;
    int Ar[size];

    int k = pow(size,0.5);
    int interval = size/k;

    cout<<"Enter elements of your array: ";
    for(int i = 0;i<size;i++){
        cin>>Ar[i];
    }
    cout<<"Enter element to search for: ";
    cin>>key;

    cout<<"The k is: "<<k<<". The interval n/k is "<<interval<<endl;

    for(int i =0;i<=interval;i++){
        if(found ==1){
            // element has already been found, break out of the for loop
            break;
        }
        if(key == Ar[k]){
            cout<<"Found at position: "<<k+1;
            break;
        }
        else
        {   numOfComparisons=numOfComparisons+1;
            if(key>Ar[ctr*k]){
                // move onto the next interval
                ctr++;
            }
            else
            {   
                if(key<Ar[ctr*k]){
                    /*
                        Linear search between 
                        (i-1)*k + 1 element and (i*k)-1 element
                    */
                    for(int p=(ctr-1)*k+1;p<ctr*k;p++){
                        if(Ar[p]==key){
                            cout<<"Found at position: "<<p+1;
                            found = 1;
                            break;
                        }
                    }
                }
            }
            if(ctr==interval){
                /*
                    There could be the case that the element lies in the last
                    interval so we search between 
                    (i*k) and the last element of the array i.e. n
                    here i = last interval value
                */
                for(int p = (ctr)*k;p<size;p++){
                    if(Ar[p]==key){
                        cout<<"Found at position: "<<p+1;
                        break;
                    }
                }   
            }
        }
    }
    cout<<endl<<"Number of comparisons: "<<numOfComparisons<<endl; // it takes lesser comparisons than naive linear search!
    if(found!=1){
        cout<<"Element not found! ";
    }

}