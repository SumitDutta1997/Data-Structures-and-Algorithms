// Rearrange an array so that a[i] becomes a[a[i]] with O(1) extra space

#include<iostream>
using namespace std;

void Rearrange(int* , int);

int main()
{
    int arr[] = {4,0,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    Rearrange(&arr[0] , n);

    return 0;
}

void Rearrange(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
        arr[i] = arr[i] + (arr[arr[i]]%n)*n ;

    for(int i=0 ; i<n ; i++)
        arr[i] = arr[i]/n;

    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";

    cout << endl;
}
