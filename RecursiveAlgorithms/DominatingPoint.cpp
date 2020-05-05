#include<iostream>
using namespace std;
struct Points{
    int x_coordinates[6];
    int y_coordinates[6];
    int rank_coordinates[6]={0};

};
// Sample input: (1,3) (2,2) (4,6) (7,1) (10,12) (13,20)
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
// Q1: a naive approach of calculating ranks - O(n^2) time complexity

void calcRanks(Points &p){
    int i,n=0,ctr=0;
    // taking array size to be 6, can make it variable
    while(n<6){
        ctr = 0;
        for(i=0;i<6;i++){
            if(p.x_coordinates[i]<p.x_coordinates[n]){
                if(p.y_coordinates[i]<p.y_coordinates[n]){
                    ctr = ctr + 1;
                }
            }
        }
        p.rank_coordinates[n] = ctr;
        n = n + 1;
    }
}

int main(){
    Points sampleSpace;
    cout<<"Enter coordinates of points: ";
    for(int i=0;i<6;i++){
        cin>>sampleSpace.x_coordinates[i];
        cin>>sampleSpace.y_coordinates[i];
    }

    cout<<"the points are: ";
    for(int i=0;i<6;i++){
        cout<<"( "<<sampleSpace.x_coordinates[i]<<" , ";
        cout<<sampleSpace.y_coordinates[i]<<" )"<<endl;
    }

    calcRanks(sampleSpace);
    for(int i=0;i<6;i++){
        cout<<sampleSpace.rank_coordinates[i]<<" ";
    }


}