// array insertion

#include<iostream>
using namespace std;

void Insert(int* , int , int , int);

int main()
{
    int n=20;
    int arr[n] = {4,6,8,2,1,5,7,3,11,17};

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
            break;
        cout << arr[i] << " ";
    }
    cout << endl;

    Insert(&arr[0] , n , 4 , 33);

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
            break;
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void Insert(int arr[] , int n , int k , int item)
{
    for(int i=n-1 ; i>=k ; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[k] = item;
    //n++;
}
