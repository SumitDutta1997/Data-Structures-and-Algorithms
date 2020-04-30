// array linear search

#include<iostream>
using namespace std;

void LinearSearch(int * , int , int);

int main()
{
    int arr[] = {3,2,5,9,8,1,4,6,19,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    LinearSearch(&arr[0] , n , 4);

    return 0;
}

void LinearSearch(int arr[] , int n , int item)
{
    int count=0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == item)
            count++;
    }
    if(count)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}
