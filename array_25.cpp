// find the smallest integer value that can't be represented as sum
// of any subset of a given array. (DOUBT)

#include<iostream>
using namespace std;

int SmallestInteger(int* , int);

int main()
{
    int arr[] = {1,3,6,10,11,15};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << SmallestInteger(&arr[0] , n) << endl;

    return 0;
}

int SmallestInteger(int arr[] , int n)
{
    int result=1;
    for(int i=0 ; i<n && arr[i] <= result ; i++)
        result = result + arr[i];

    return result;
}
