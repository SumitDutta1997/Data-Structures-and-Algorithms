// Find the sum of first n natural numbers using recursion

#include<iostream>
using namespace std;

int NnaturalNumbers(int);

int main()
{
    int n = 2;

    cout << NnaturalNumbers(n);

    return 0;
}

int NnaturalNumbers(int n)
{
    if(n==0)
        return 0;
    else
        return n+NnaturalNumbers(n-1);
}
