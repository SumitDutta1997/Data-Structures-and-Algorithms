// Fibonacci Series using recursion (improvement)

#include<iostream>
using namespace std;

int fibonacci(int);
int F[10];

int main()
{
    for(int i=0 ; i<10 ; i++)
        F[i] = -1;

    cout << fibonacci(7);

    return 0;
}

int fibonacci(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2] == -1)
            F[n-2] = fibonacci(n-2);
        if(F[n-1] == -1)
            F[n-1] = fibonacci(n-1);

        return F[n-2]+F[n-1];
    }
}
