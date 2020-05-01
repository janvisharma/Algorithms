#include<iostream>
#include<math.h>
using namespace std;

int Karatsuba(long x, long y){
    int lengthOfX = to_string(x).length();
    int lengthOfY = to_string(y).length();
    int N;
    if(lengthOfX>lengthOfY){
        N = lengthOfX;
    }
    else{
        N = lengthOfY;
    }

    N = (N/2) + (N%2);

    long powerN = pow(10,N);

    long a = x/powerN;
    long b = x - (a*powerN);

    long c = y/powerN;
    long d = y - (c*powerN);

    long z0 = Karatsuba(b,d);
    long z1 = Karatsuba(a+b, c+d);
    long z2 = Karatsuba(a,c);

    return z0 + ((z1-z0-z2)*N) + (z2*(long)(pow(10,2*N)));

}


int main(){
    long x, y;
    cout<<"Enter two numbers you want to multiply: ";
    cin>>x>>y;

    long product = Karatsuba(x,y);
    cout<<"The result is: "<<product;
}
