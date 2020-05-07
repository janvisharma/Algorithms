#include<iostream>
#include <algorithm> 
using namespace std;

/*  
    Problem statement:
    Consider a set S of n points on a two-dimensional plane. Each point p_i
    is given by a pair of co-ordinates x_i , y_i . A point p_i is said to dominate
    another point p_j iff x_i > x_j and y_i > y_j . That is, p_i ’s values are larger
    than those of p_j in both dimensions. The rank of a point p_i , denoted
    by R(p_i ), is defined as the number of points in S that are dominated
    by p_i . 
    Assume that S is represented by two arrays X[1..n]
    and Y [1..n] such that the coordinates of p_i are given by (X[i], Y [i]).

*/
// Sample input: (1,3) (2,2) (4,6) (7,1) (10,12) (13,20)

void FindRank(int x[], int y[], int r[],int n){
    if(n==1){
        cout<<"base case "<<x[0]<<endl;
        r[0] = 0;
        return;
    }
    else{
        
}
// use vectors instead of arrays + use partition 

int main(){
    cout<<"enter no. of coordinates: ";
    int n;
    cin>>n;
    int P_x[n], P_y[n];
    int P_r[n] = {0};

    cout<<"Enter the coordinates: ";
    for(int i=0;i<n;i++){
        cin>>P_x[i]>>P_y[i];
    }

    FindRank(P_x,P_y,P_r,n);
    // try returning an arr 
    for(int i=0;i<n;i++){
        cout<<P_r[i]<<" ";
    }

}