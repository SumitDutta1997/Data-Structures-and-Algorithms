// Fibonacci Series using recursion

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
        return n;

    return fibonacci(n-2)+fibonacci(n-1);
}
