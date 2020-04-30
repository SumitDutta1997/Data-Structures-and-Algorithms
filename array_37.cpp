// sort an array consisting of 0's , 1's , 2's

#include<iostream>
using namespace std;

void Sort012(int* , int);

int main()
{
    int arr[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    Sort012(&arr[0] , n);

    return 0;
}

/* void Sort012(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j] , arr[j+1]);
        }
    }
    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
}
*/

void Sort012(int arr[] , int n)
{
    int ZeroCount=0 , OneCount=0 , TwoCount=0;

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
            ZeroCount++;
        if(arr[i] == 1)
            OneCount++;
        if(arr[i] == 2)
            TwoCount++;
    }

    for(int i=0 ; i<ZeroCount ; i++)
        arr[i] = 0;

    for(int i=ZeroCount ; i<(ZeroCount+OneCount) ; i++)
        arr[i] = 1;

    for(int i=(ZeroCount+OneCount) ; i<n ; i++)
        arr[i] = 2;

    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
}
