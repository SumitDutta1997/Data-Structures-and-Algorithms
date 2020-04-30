// Find max value of a[j]-a[i]+a[l]-a[k] for every four indices i,j,k,l such that i<j<k<l

#include<iostream>
using namespace std;

int maxValue(int* , int);

int main()
{
    int arr[] = {4,8,9,2,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxValue(&arr[0] , n) << endl;

    return 0;
}

int maxValue(int arr[] , int n)
{
    int Max=0;
    for(int i=0 ; i<n-3 ; i++)
    {
        for(int j=i+1 ; j<n-2 ; j++)
        {
            for(int k=j+1 ; k<n-1 ; k++)
            {
                for(int l=k+1 ; l<n ; l++)
                {
                    if(arr[j]-arr[i] + arr[l]-arr[k] > Max)
                        Max = arr[j]-arr[i] + arr[l]-arr[k];
                }
            }
        }
    }
    return Max;
}
