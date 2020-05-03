#include<iostream>
using namespace std;
struct Points{
    int x_coordinates[6];
    int y_coordinates[6];
    int rank_coordinates[6]={0};
};
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
void calcRanks(Points &p, int start, int end){
    int size = sizeof(p.rank_coordinates)/sizeof(p.rank_coordinates[0]);
    if(size==1){
        p.rank_coordinates[0] = 0;
    }
    else{
        int mid = start+(end-start)/2;
        
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

    calcRanks(sampleSpace,0,5);
    for(int i=0;i<6;i++){
        cout<<sampleSpace.rank_coordinates[i]<<" ";
    }

}