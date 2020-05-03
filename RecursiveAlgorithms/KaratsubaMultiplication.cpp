#include<iostream>
#include<math.h>
using namespace std;

int Karatsuba(long x, long y){
    int lengthOfX = to_string(x).length();
    int lengthOfY = to_string(y).length();
    if(lengthOfX<2||lengthOfY<2){
        return x*y;
    }

    long a,b,c,d;
    long z1,z2,z3,z4;

    a = x/pow(10,int(lengthOfX/2));
    b = x - a*pow(10,int(lengthOfX/2));

    c = y/pow(10,int(lengthOfY/2));
    d = y - c*pow(10,int(lengthOfY/2));

    cout<<a<<" "<<b;
    cout<<c<<" "<<d;

    z1 = Karatsuba(a,c);
    z2 = Karatsuba(b,d);
    z3 = Karatsuba(a+b,c+d);
    z4 = z3 - z1 - z2;

    return z1*pow(10,lengthOfX)+z4*pow(10,lengthOfX/2)+z2;

}

// code needs to be modified to handle input of different lengths

int main(){
    long x, y;
    cout<<"Enter two numbers you want to multiply: ";
    cin>>x>>y;

    long product = Karatsuba(x,y);
    cout<<"The result is: "<<product<<endl;
}
