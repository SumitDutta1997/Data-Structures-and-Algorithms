// Maximum difference between two elements such that larger element appears after the smaller element

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {7,3,8,2,4,6,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_diff = arr[1] - arr[0];

    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j]-arr[i] > max_diff)
                max_diff = arr[j] - arr[i];
        }
    }

    cout << max_diff << endl;

    return 0;
}
