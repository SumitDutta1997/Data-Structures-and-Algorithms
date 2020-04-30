// Combination formula using recursion (Pascal's Triangle)

#include<iostream>
using namespace std;

int Combination(int, int);

int main()
{
    int n=6 , r=2;

    cout << Combination(n,r);

    return 0;
}

int Combination(int n , int r)
{
    if(r==0 || r==n)
        return 1;
    else
        return Combination(n-1,r-1)+Combination(n-1,r);
}
