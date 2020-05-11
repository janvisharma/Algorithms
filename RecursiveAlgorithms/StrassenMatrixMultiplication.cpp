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
void addMatrix(vector<vector<int>>&A, vector<vector<int>>&B,vector<vector<int>>&T, int n){
    int i, j,sum = 0;
    for(i=0;i<n;i++){
        sum = 0;
        for(j=0;j<n;j++){
            sum = A[i][j] + B[i][j];
            T[i][j] = sum;
        }
    }
}
void subMatrix(vector<vector<int>>&A, vector<vector<int>>&B,vector<vector<int>>&T, int n){
    int i, j,dif = 0;
    for(i=0;i<n;i++){
        dif = 0;
        for(j=0;j<n;j++){
            dif = A[i][j] - B[i][j];
            T[i][j] = dif;
        }
    }
}
/*
    Time complexity for merge matrix
    Since it requires n^2 assignments
    It loops through n^2 elements 
    O(n^2) depends on size of matrix
*/
void mergeMatrix(vector<vector<int>>&C11,vector<vector<int>>&C12,vector<vector<int>>&C21,vector<vector<int>>&C22,vector<vector<int>>&C,int n){
    int i,j;
    // size of matrix C is 2n

        // top left block  
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                C[i][j] = C11[i][j];
            }
        }

        // top right block 
        for(i=0;i<n;i++){
            int k = 0;
            for(j=n;j<2*n;j++){
                int m = 0;
                C[i][j] = C12[k][m];
                m++;
            }
            k++;
        }

        // bottom left block 
        for(i=n;i<2*n;i++){
            int k = 0;
            for(j=0;j<n;j++){
                int m = 0;
                C[i][j] = C21[k][m];
                m++;
            }
            k++;
        }
        // bottom right block 
        for(i=n;i<2*n;i++){
            int k = 0;
            for(j=n;j<2*n;j++){
                int m = 0;
                C[i][j] = C22[k][m];
                m++;
            }
            k++;
        }

}

void StrassenMM(vector<vector<int>> &A,vector<vector<int>> &B,vector<vector<int>> &C,int n){
    if(n==1){
        C[0][0] = A[0][0]*B[0][0]; // O(1) 
    }
    else{
        int size = n/2;
        
        vector<vector<int>>A11(size),A12(size),A21(size),A22(size);
        vector<vector<int>>B11(size),B12(size),B21(size),B22(size);
        vector<vector<int>>C11(size),C12(size),C21(size),C22(size);
    
        initZero(C11,n/2);
        initZero(C12,n/2);
        initZero(C21,n/2);
        initZero(C22,n/2);

        initZero(A11,n/2);
        initZero(A12,n/2);
        initZero(A21,n/2);
        initZero(A22,n/2);

        initZero(B11,n/2);
        initZero(B12,n/2);
        initZero(B21,n/2);
        initZero(B22,n/2);

        vector<vector<int>>P1(n/2),P2(n/2),P3(n/2),P4(n/2),P5(n/2),P6(n/2),P7(n/2);
        initZero(P1,n/2);
        initZero(P2,n/2);
        initZero(P3,n/2);
        initZero(P4,n/2);
        initZero(P5,n/2);
        initZero(P6,n/2);
        initZero(P7,n/2);

        int i, j;
        
        // top left block  
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                A11[i][j] = A[i][j];
                B11[i][j] = B[i][j];
            }
        }
      
        // top right block 
        for(i=0;i<n/2;i++){
            int k = 0;
            for(j=n/2;j<n;j++){
                int m = 0;
                A12[k][m] = A[i][j];
                B12[k][m] = B[i][j];
                m++;
            }
            k++;
        }
        // bottom left block 
        for(i=n/2;i<n;i++){
            int k = 0;
            for(j=0;j<n/2;j++){
                int m = 0;
                A21[k][m] = A[i][j];
                B21[k][m] = B[i][j];
                m++;
            }
            k++;
        }
        // bottom right block 
        for(i=n/2;i<n;i++){
            int k = 0;
            for(j=n/2;j<n;j++){
                int m = 0;
                A22[k][m] = A[i][j];
                B22[k][m] = B[i][j];
                m++;
            }
            k++;
        }
        vector<vector<int>>TEMP1(n/2),TEMP2(n/2);
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        addMatrix(A11,A22,TEMP1,n/2);
        addMatrix(B11,B22,TEMP2,n/2);
        StrassenMM(TEMP1,TEMP2,P1,n/2); // P1
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        addMatrix(A21,A22,TEMP1,n/2);
        StrassenMM(TEMP1,B11,P2,n/2); // P2
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        subMatrix(B12,B22,TEMP2,n/2);
        StrassenMM(A11,TEMP2,P3,n/2); // P3
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        subMatrix(B21,B11,TEMP1,n/2);
        StrassenMM(A22,TEMP1,P4,n/2); // P4
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        addMatrix(A11,A12,TEMP1,n/2);
        StrassenMM(TEMP1,B22,P5,n/2); // P5
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        subMatrix(A21,A11,TEMP1,n/2);
        addMatrix(B11,B12, TEMP2,n/2);
        StrassenMM(TEMP1,TEMP2,P6,n/2); // P6
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        subMatrix(A12,A22, TEMP1,n/2);
        addMatrix(B21,B22,TEMP2,n/2);
        StrassenMM(TEMP1,TEMP2,P7,n/2); // P7
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        addMatrix(P3,P5,C12,n/2);
        addMatrix(P2,P4,C21,n/2);

        addMatrix(P1,P4,TEMP1,n/2);
        addMatrix(TEMP1,P7,TEMP2,n/2);
        subMatrix(TEMP2,P5,C11,n/2);
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);

        addMatrix(P1,P3,TEMP1,n/2);
        addMatrix(TEMP1,P6,TEMP2,n/2);
        subMatrix(TEMP2,P2,C22,n/2);
        mergeMatrix(C11,C12,C21,C22,C,n/2);

    }

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