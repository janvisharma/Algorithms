#include<iostream>
#include<vector>
using namespace std;

void MatrixSum(vector<vector<int>>&A, vector<vector<int>>&B, vector<vector<int>>&C,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

}

void initZero(vector<vector<int>>&R, int n){
    int i,j,value =0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            R[i].push_back(value);
        }
    }
}

void mergeMatrix(vector<vector<int>>C11,vector<vector<int>>C12,vector<vector<int>>C21,vector<vector<int>>C22,vector<vector<int>>&C,int n){
    int i,j;
    // size of matrix C is 2n

        // top left block  
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                C[i][j] = C11[i][j];
            }
        }

        // top right block 
        for(i=0;i<n/2;i++){
            int k = 0;
            for(j=n/2;j<n;j++){
                int m = 0;
                C[i][j] = C12[k][m];
                m++;
            }
            k++;
        }

        // bottom left block 
        for(i=n/2;i<n;i++){
            int k = 0;
            for(j=0;j<n/2;j++){
                int m = 0;
                C[i][j] = C21[k][m];
                m++;
            }
            k++;
        }
        // bottom right block 
        for(i=n/2;i<n;i++){
            int k = 0;
            for(j=n/2;j<n;j++){
                int m = 0;
                C[i][j] = C22[k][m];
                m++;
            }
            k++;
        }

}
int multiplyMatrix(vector<vector<int>>&A, vector<vector<int>>&B){
    return A[0][0]*B[0][0];
}

void SquareMatrixMultiply(vector<vector<int>>&A, vector<vector<int>>&B, vector<vector<int>>&C,int n){
    vector<vector<int>>An(1), Bn(1);

    if(n==1){
        C[0][0] = A[0][0]*B[0][0];
    }
    else {
        cout<<"statement 1";
        int size = n/2;
        
        vector<vector<int>>A11(size),A12(size),A21(size),A22(size);
        vector<vector<int>>B11(size),B12(size),B21(size),B22(size);
        vector<vector<int>>C11(size),C12(size),C21(size),C22(size);
        cout<<"statement 2";
    
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
    

        vector<vector<int>>TEMP1(n/2),TEMP2(n/2);

        int i, j;
        
        // top left block  
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                A11[i][j] = A[i][j];
                B11[i][j] = B[i][j];
            }
        }
        cout<<"statement 3";
 
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
        cout<<"statement 4";
        SquareMatrixMultiply(A11,B11,TEMP1,n/2);
        SquareMatrixMultiply(A12,B21,TEMP1,n/2);
        MatrixSum(TEMP1,TEMP2,C11,n/2);
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);
        cout<<"statement 5";

        SquareMatrixMultiply(A11,B12,TEMP1,n/2);
        SquareMatrixMultiply(A12,B22,TEMP1,n/2);
        MatrixSum(TEMP1,TEMP2,C12,n/2);
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);
        cout<<"statement 6";

        SquareMatrixMultiply(A21,B11,TEMP1,n/2);
        SquareMatrixMultiply(A22,B21,TEMP1,n/2);
        MatrixSum(TEMP1,TEMP2,C21,n/2);
        initZero(TEMP1,n/2);
        initZero(TEMP2,n/2);
        cout<<"statement 7";

        SquareMatrixMultiply(A21,B12,TEMP1,n/2);
        SquareMatrixMultiply(A22,B22,TEMP1,n/2);
        MatrixSum(TEMP1,TEMP2,C22,n/2);
        cout<<"statement 8";
        mergeMatrix(C11,C12,C21,C22,C,n/2);
        cout<<"statement 9";

    }
}

int main(){

    cout<<"Enter size of your matrix ";
    int n;
    cin>>n;

    vector<vector<int>> A(2);
    vector<vector<int>> B(2);
    vector<vector<int>> C(2);

    int i, j,value;

    initZero(C,2);

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
  

    SquareMatrixMultiply(A,B,C,n);
    cout<<endl<<"the result is "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}