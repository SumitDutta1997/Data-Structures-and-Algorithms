// Search an element in a sorted rotated array

#include<iostream>
using namespace std;

void SearchElement(int* , int , int);
int BinarySearch(int* , int , int , int);

int main()
{
    int arr[] = {30,40,50,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 10;

    SearchElement(&arr[0] , n , key);

    return 0;
}

void SearchElement(int arr[] , int n , int key)
{
    int i;
    for(i=0 ; i<n ; i++)
    {
        if(arr[i+1] < arr[i])
            break;
    }

    if(key < arr[0])
        cout << "Found at index " << BinarySearch(&arr[0] , i+1 , n-1 , key) << endl;
    else
        cout << "Found at index " << BinarySearch(&arr[0] , 0 , i , key) << endl;
}

int BinarySearch(int arr[] , int low , int high , int item)
{
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
