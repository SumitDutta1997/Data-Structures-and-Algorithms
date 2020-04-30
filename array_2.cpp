// array deletion

#include<iostream>
using namespace std;

void Deletion(int* , int , int);

int main()
{
    int n=20;
    int arr[n] = {2,9,3,6,8,1,4,5,7,11};

    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]==0)
            break;

        cout << arr[i] << " ";
    }
    cout << endl;

    Deletion(&arr[0] , 5 , n);
    //Deletion(&arr[0] , 5 , 10);

    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";

        if(arr[i]==0)
            break;
    }
    cout << endl;

    return 0;
}

void Deletion(int arr[] , int k , int n)
{
    for(int i=k+1 ; i<=n ; i++)
    {
        arr[i-1] = arr[i];
    }
    //n--;
}
