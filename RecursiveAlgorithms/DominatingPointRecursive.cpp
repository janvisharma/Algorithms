#include <iostream>
#include <algorithm> 
#include <vector>
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

void FindRank(vector<int>&x, vector<int>&y,vector<int>&r,int n){
    if(n==1){
        cout<<"base case "<<x[0]<<endl;
        r[0] = 0;
        return;
    }
    else{
        int sum=0;
        for(int i=0;i<n;i++){
            sum = sum + x[i];
        }
        int mid = int(sum/n);
        stable_partition(x.begin(),x.end(),[v=mid](int n){return n<v;});
        
        vector<int> SL_x,SL_y,SH_x,SH_y,SL_r,SH_r;
        mid = int(n/2);

        for(int i=0;i<mid;i++){
            SL_x.push_back(x[i]);
            SL_y.push_back(y[i]);
            SL_r.push_back(r[i]);
        }
        for(int i=mid;i<n;i++){
            SH_x.push_back(x[i]);
            SH_y.push_back(y[i]);
            SH_r.push_back(r[i]);
        }


        FindRank(SL_x,SL_y,SL_r,SL_x.size());
        FindRank(SH_x,SH_y,SH_r,SH_x.size());
        int i=0, j=0;
        for(i=0;i<SL_y.size();i++){
            for(j=0;j<SH_y.size();j++){
                if(SL_y[i]<SH_y[i]){
                    SH_r[i] += 1;
                    cout<<SH_r[i]<<" ";
                }
            }
        }
        for(i=mid;i<n;i++){
            r[i] = SH_r[i];
        }

    }    
}


int main(){
    cout<<"enter no. of coordinates: ";
    int n,i;
    cin>>n;
    vector<int> P_x(n), P_y(n), P_r(n);
    for(i=0;i<n;i++){
        P_r[i] = 0;
    }
    int val_x, val_y;
    cout<<"Enter the coordinates : ";
    for(i=0;i<n;i++){
        cin>>val_x;
        P_x[i] = val_x;
        cin>>val_y;
        P_y[i] = val_y;
    }

    for(i=0;i<n;i++){
        cout<<P_r[i]<<" "<<P_x[i]<<" "<<P_y[i]<<endl;
    }
    FindRank(P_x,P_y,P_r,n);
    for(i=0;i<n;i++){
        cout<<P_r[i]<<" "<<P_x[i]<<" "<<P_y[i]<<endl;
    }

}