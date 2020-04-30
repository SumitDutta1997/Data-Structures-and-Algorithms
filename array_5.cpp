// array bubble sort

#include<iostream>
using namespace std;

void BubbleSort(int* , int);

int main()
{
    int arr[] = {10,8,5,3,6,9,1,4,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted : ";
    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(&arr[0] , n);

    cout << "Sorted   : ";
    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void BubbleSort(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}
