// array Binary search

#include<iostream>
using namespace std;

int BinarySearch(int * , int  , int);

int main()
{
    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(BinarySearch(&arr[0] , 5 , n) == -1)
        cout << "Not Found" << endl;
    else
        cout << "Found" << endl;

    return 0;
}

int BinarySearch(int arr[] , int item , int n)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==item)
            return mid;

        else if(item < arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}
