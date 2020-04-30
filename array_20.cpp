// find max difference of 'j' and 'i' such that a[j] > a[i] in an array

#include<iostream>
using namespace std;

int MaxDifference(int* , int);

int main()
{
    int arr[] = {34,8,10,3,2,80,30,33,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << MaxDifference(&arr[0] , n) << endl;

    return 0;
}

int MaxDifference(int arr[] , int n)
{
    int newDiff = 0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[i] < arr[j] && newDiff < (j-i))
                newDiff = j-i;
        }
    }
    return newDiff;
}
