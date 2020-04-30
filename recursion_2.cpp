// Find the factorial of a number using recursion

#include<iostream>
using namespace std;

int factorial(int);

int main()
{
    int n = 5;

    cout << factorial(n);

    return 0;
}

int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
