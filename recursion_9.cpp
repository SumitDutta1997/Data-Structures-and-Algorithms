// Taylor Series (e^x) using recursion

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
    static double p=1 , f=1;
    double result;

    if(n==0)
        return 1;

    else
    {
        result = E(x,n-1);
        p = p * x;
        f = f * n;

        return result + p/f;
    }
}
