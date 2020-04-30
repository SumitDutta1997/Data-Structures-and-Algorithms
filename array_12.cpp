//check for pair in A[] with sum as X

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,4,45,6,10,-8};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x=2;
    for(int i=0 ; i<n ; i++)
    {
        int result = x-arr[i];
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j] == result)
            {
                cout << "Yes" << " ";
                cout << "(" << arr[i] << "," << arr[j] << ")";
            }
        }
    }

    return 0;
}
