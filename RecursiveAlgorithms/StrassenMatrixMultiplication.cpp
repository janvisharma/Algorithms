#include<iostream>
#include<vector>
using namespace std;

void initZero(vector<vector<int>>&R, int n){
    int i,j,value =0;
    // O(n^2)
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            R[i].push_back(value);
        }
    }
}
void StrassenMM(vector<vector<int>> &A,vector<vector<int>> &B,vector<vector<int>> &C,int n){


}
int main(){
    cout<<"Enter size of your matrix ";
    int n;
    cin>>n;

    vector<vector<int>> A(n);
    vector<vector<int>> B(n);
    vector<vector<int>> C(n);

    int i, j,value;

    initZero(C,n);

    cout<<"Enter elements of array A: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            value = 0;
            cin>>value;
            A[i].push_back(value);
        }
    }
    
    cout<<"Enter elements of array B: "<<endl;

    int val;
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
          
            cin>>val;
            B[i].push_back(val);
           
        }
        
    }
  
    StrassenMM(A,B,C,n);

    cout<<endl<<"The resultant matrix is: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}