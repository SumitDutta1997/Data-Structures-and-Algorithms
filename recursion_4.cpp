// Find the exponential for a number using recursion (improvement)

#include<iostream>
using namespace std;

int exponent(int , int);

int main()
{
    int m=2 , n=5;

    cout << exponent(m,n);

    return 0;
}

int exponent(int m , int n)
{
    if(n==0)
        return 1;

    if(n%2==0)
        return exponent(m*m,n/2);
    else
        return m*exponent(m*m,n/2);
}
