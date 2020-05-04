#include<iostream>
#include <algorithm> 
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


void calcRanks(Points p, int start, int end){
    int size = sizeof(p.rank_coordinates)/sizeof(p.rank_coordinates[0]);
    if(start==end){
        cout<<"base case "<<endl;
        p.rank_coordinates[start] = 0;
        return;
    }
    else{
        // cout<<"statement 1 "<<endl;
        int mid = start+(end-start)/2;
        Points SL,SH;
        int i;
        for(i=0;i<mid+1;i++){
            SL.x_coordinates[i] = p.x_coordinates[i];
            SL.y_coordinates[i] = p.y_coordinates[i];
            SL.rank_coordinates[i] = p.rank_coordinates[i];
        }
        int j = 0;
        for(i=mid+1;i<end+1;i++){
            SH.x_coordinates[j] = p.x_coordinates[i];
            SH.y_coordinates[j] = p.y_coordinates[i];
            SH.rank_coordinates[j] = p.rank_coordinates[i];
            j = j + 1;
        }
        int nL = sizeof(SL.y_coordinates)/sizeof(SL.y_coordinates[0]); 
        cout<<"size of SL is "<<nL<<endl;
        
        // cout<<"statement 2 "<<endl;
        calcRanks(SL, 0, mid);
        calcRanks(SH, mid+1, end);
    
        cout<<"statement 3 "<<endl;
        i = 0, j = 0;
        
        sort(SL.y_coordinates, SL.y_coordinates+nL);
        cout<<"statement 4 "<<endl;
        int nH = sizeof(SH.y_coordinates)/sizeof(SH.y_coordinates[0]); 
        sort(SH.y_coordinates,SH.y_coordinates+nH);
        cout<<"statement 5 "<<endl;
        while(i<mid+1){
            cout<<"statement 6 "<<endl;
            if(SL.y_coordinates[i]<SH.y_coordinates[j]){
                SH.rank_coordinates[j] += SH.rank_coordinates[j];
                j = j + 1;
            }
            else{
                if(SL.y_coordinates[i]>SH.y_coordinates[j]){
                    i = i + 1;
                    j = 0;
                }
            }
            if(j==end+1){
                i = i + 1;
                j = 0;
            }
        }
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