// array sorting using STL

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {1,9,3,7,5,4,2,8,6,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "unsorted : ";
    for(int i=0 ; i<n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr , arr + n);

    cout << "sorted   : ";
    for(int i=0 ; i<n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
