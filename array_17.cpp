// Find two repeating numbers in an array

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

void TwoRepeatingNumbers(int* , int);

int main()
{
    int arr[] = {4,2,4,5,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    TwoRepeatingNumbers(&arr[0] , n);

    return 0;
}

void TwoRepeatingNumbers(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[i] == arr[j])
                cout << arr[i] << " ";
        }
    }
}

/* void TwoRepeatingNumbers(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];

        else
            cout << abs(arr[i]) << " ";
    }
}
*/

/* int fact(int n)
{
    return (n==0) ? 1 : n*fact(n-1);
}

void TwoRepeatingNumbers(int arr[] , int size)
{
    int x,y;
    int s=0;
    int p=1;
    int d;
    int n = size-2;

    for(int i=0 ; i<size ; i++)
    {
        s = s + arr[i];
        p = p * arr[i];
    }

    s = s - n*(n+1)/2;
    p = p / fact(n);

    d = sqrt(s*s - 4*p);

    x = (s+d)/2;
    y = (s-d)/2;

    cout << x << " " << y << endl;
}
*/
