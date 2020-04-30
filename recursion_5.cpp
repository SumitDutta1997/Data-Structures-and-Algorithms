// Taylor Series (e^x) using recursion (Horner's Rule)

#include<iostream>
using namespace std;

double E(int, int);

int main()
{
    int x=1 , n=10;

    cout << E(x,n);

    return 0;
}

double E(int x , int n)
{
    static double s=1;

    if(n==0)
        return s;

    s=1+x*s/n;

    return E(x,n-1);
}
