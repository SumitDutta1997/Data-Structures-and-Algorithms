// sort the array into a wave like array and return it.
// a1 >= a2 <= a3 >= a4 <= a5 ....etc

#include<iostream>
using namespace std;

void WaveArray(int* , int);

int main()
{
    int arr[] = {10,5,6,3,2,20,100,80};
    int n = sizeof(arr)/sizeof(arr[0]);

    WaveArray(&arr[0] , n);

    return 0;
}

void WaveArray(int arr[] , int n)
{
    for(int i=0 ; i<n-1 ; i++)
    {
        if(i%2==0)
        {
            if(arr[i] < arr[i+1])
                swap(arr[i] , arr[i+1]);
        }
        else
        {
            if(arr[i] > arr[i+1])
                swap(arr[i] , arr[i+1]);
        }
    }
    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
}

/* void WaveArray(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if (i>0 && arr[i-1] > arr[i] )
            swap(&arr[i], &arr[i-1]);

        // If current even element is smaller than next
        if (i<n-1 && arr[i] < arr[i+1] )
            swap(&arr[i], &arr[i + 1]);
    }
}
*/
