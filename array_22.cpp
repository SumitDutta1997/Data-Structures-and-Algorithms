// find a sub array whose sum is x in an array

#include<iostream>
using namespace std;

int SubArray(int* , int , int);

int main()
{
    int arr[] = {1,4,0,0,3,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 7;

    SubArray(&arr[0] , n , x);

    return 0;
}

int SubArray(int arr[] , int n , int x)
{
    int sum = arr[0];
    int start=0;
    for(int i=1 ; i<=n ; i++)
    {
        while(sum > x && start < i+1)
        {
            sum = sum - arr[start];
            start++;
        }
        if(sum == x)
        {
            cout << start << " to " << i-1 << endl;
            return 1;
        }
        if(i<n)
            sum = sum + arr[i];
    }
    cout << "No subarray found!" << endl;
    return 0;
}
