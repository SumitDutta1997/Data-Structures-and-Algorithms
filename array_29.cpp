// find next greater number formed after permuting the digits of a given number.

#include<iostream>
using namespace std;

void NextGreaterNumber(int* , int);

int main()
{
    int arr[] = {2,1,8,7,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    NextGreaterNumber(&arr[0] , n);

    return 0;
}

void NextGreaterNumber(int arr[] , int n)
{
    int i , flag=0;
    for(i=n-2 ; i>=0 ; i--)
    {
        if(arr[n-1] > arr[i])
        {
            swap(arr[n-1] , arr[i]);
            break;
        }
    }
    if(i>=0)
    {
        flag=1;
        for(int k=i+1 ; k<n ; k++)
        {
            for(int j=i+1 ; j<n-1 ; j++)
            {
                if(arr[j] > arr[j+1])
                    swap(arr[j] , arr[j+1]);
            }
        }
        for(int l=0 ; l<n ; l++)
            cout << arr[l];
    }
    if(flag==0)
        cout << "Not Possible!";
}
