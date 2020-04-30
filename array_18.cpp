// Find duplicates in O(n) time and O(1) extra space in an array

#include<iostream>
#include<stdlib.h>
using namespace std;

void Duplicates(int* , int);

int main()
{
    int arr[] = {1,6,3,1,3,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    Duplicates(&arr[0] , n);

    return 0;
}

void Duplicates(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}

/* void Duplicates(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }

    for (int i = 0; i < n; i++)
    {
        if ((arr[i]/n) > 1)
            cout << i << " ";
    }
}
*/
