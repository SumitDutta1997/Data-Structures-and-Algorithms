// find triplet whose sum is X in an array

#include<iostream>
using namespace std;

bool Triplet(int* , int , int);

int main()
{
    int arr[] = {12,3,4,1,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x=24;

    Triplet(&arr[0] , n , x);

    return 0;
}

/* bool Triplet(int arr[] , int n , int x)
{
    for(int i=0 ; i<n-2 ; i++)
    {
        int l = i+1;
        int r = n-1;

        while(l<r)
        {
            if(arr[i]+arr[l]+arr[r] == x)
            {
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                return true;
            }
            else if(arr[i]+arr[l]+arr[r] < x)
                l++;
            else
                r--;
        }
    }
    return false;
}
*/

bool Triplet(int arr[] , int n , int x)
{
    for(int i=0 ; i<n-2 ; i++)
    {
        for(int j=i+1 ; j<n-1 ; j++)
        {
            for(int k=j+1 ; k<n ; k++)
            {
                if(arr[i]+arr[j]+arr[k] == x)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    return true;
                }
            }
        }
    }
    return false;
}
