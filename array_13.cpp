// segregate 0's and 1's

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {0,1,0,1,0,0,1,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
            count = count+1;
    }
    for(int i=0 ; i<count ; i++)
        arr[i] = 0;
    for(int i=count ; i<n ; i++)
        arr[i] = 1;

    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";

    return 0;
}
