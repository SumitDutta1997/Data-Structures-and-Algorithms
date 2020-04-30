// Given an array and an integer K, find the maximum for
// each and every contiguous sub-array of size K

#include<iostream>
using namespace std;

void maxElement(int* , int , int);

int main()
{
    int arr[] = {8,5,10,7,9,4,15,12,90,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    maxElement(&arr[0] , n , k);

    return 0;
}

void maxElement(int arr[] , int n , int k)
{
    for(int i=0 ; i<=n-k ; i++)
    {
        int Max = arr[i];
        for(int j=i ; j<k+i-1 ; j++)
        {
            if(Max < arr[j+1])
                Max = arr[j+1];
        }
        cout << Max << " ";
    }
}
