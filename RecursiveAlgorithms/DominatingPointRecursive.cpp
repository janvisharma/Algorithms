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
    }
    else{
        int mid = int(n/2);
        int SL_x[mid], SH_x[mid], SL_y[mid], SH_y[mid], SL_r[mid], SH_r[mid];
        int i;
        for(i=0;i<mid;i++){
            SL_x[i] = x[i];
            SL_y[i] = y[i];
            SL_r[i] = r[i];
        }
        int j = 0;
        for(i=mid;i<n;i++){
            SH_x[j] = x[i];
            SH_y[j] = y[i];
            SH_r[j] = r[i];
            j = j + 1;
        }

        int sL = sizeof(SL_r)/sizeof(SL_r[0]);
        FindRank(SL_x, SL_y, SL_r, sL);

        int sH = sizeof(SH_r)/sizeof(SH_r[0]);
        FindRank(SH_x, SH_y, SH_r, sH);
        
        for(i=0;i<sL;i++){
            cout<<SL_x[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<sH;i++){
            cout<<SH_x[i]<<" ";
        }
        cout<<endl;
        sort(SL_y,SL_y+sL);
        sort(SH_y,SH_y+sH);
        cout<<"sorted y ";
        for(i = 0;i<sL;i++){
            cout<<SL_y[i]<<" ";
        }
        i = 0, j = 0;
        while(i<sL){
            cout<<"inside while "<<endl;
            if(SL_y[i]<SH_y[j]){
                cout<<"comparing "<<SL_y[i]<<" < "<<SH_y[i]<<endl;
                cout<<"inc "<<SH_x[j]<<" "<<SH_r[j]<<" ";
                SH_r[j] = SH_r[j] + 1;
                j = j + 1;
            }
            if(SL_y[i]>SH_y[j]){
                cout<<"comparing "<<SL_y[i]<<" > "<<SH_y[i]<<endl;
                i = i + 1;
                j = 0;
            }
            if(j==sH){
                i = i + 1;
                j = 0;
            }
        }
    cout<<"SHR is ";
    for(i=0;i<sL;i++){
        cout<<SH_r[i]<<" "; 
    }
    cout<<endl;
    }

    
}

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
    for(int i=0;i<n;i++){
        cout<<P_r[i]<<" ";
    }

}