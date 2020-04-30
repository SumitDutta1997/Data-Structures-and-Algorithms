// to reverse an array

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i=0 ; i<n ; i++)
        cin >> arr[i];

    for(int i=0 ; i<(n-1-i) ; i++)
        swap(arr[i] , arr[n-1-i]);

    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";

    return 0;
}
