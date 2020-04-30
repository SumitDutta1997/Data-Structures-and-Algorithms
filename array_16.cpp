// Merge an array of size 'n' into another array of size 'm+n'

#include<iostream>
using namespace std;

#define NA -1

void MoveToEnd(int* , int);
void Merge(int* , int* , int , int);
void printArray(int* , int);

int main()
{
    int mPlusN[] = {2,8,NA,NA,NA,13,NA,15,20};
    int N[] = {5,7,9,25};

    int n = sizeof(N)/sizeof(N[0]);
    int m = sizeof(mPlusN)/sizeof(mPlusN[0])- n;

    MoveToEnd(&mPlusN[0] , m+n);

    Merge(&mPlusN[0] , &N[0] , m , n);

    printArray(&mPlusN[0] , m+n);

    return 0;
}

void MoveToEnd(int mPlusN[] , int length)
{
    int j = length-1;
    for(int i=length-1 ; i>=0 ; i--)
    {
        if(mPlusN[i] != NA)
        {
            mPlusN[j] = mPlusN[i];
            j--;
        }
    }
}

void Merge(int mPlusN[] , int N[] , int m , int n)
{
    int i=n;
    int j=0;
    int k=0;
    while(k<(m+n))
    {
        if((i<(m+n) && mPlusN[i]<=N[j]) || (j==n))
        {
            mPlusN[k] = mPlusN[i];
            k++;
            i++;
        }
        else
        {
            mPlusN[k] = N[j];
            k++;
            j++;
        }
    }
}

void printArray(int mPlusN[] , int length)
{
    for(int i=0 ; i<length ; i++)
        cout << mPlusN[i] << " ";

    cout << endl;
}
