// find index such that the sum of elements at lower indexes is equal to the sum of element at higher indexes
// OR find the Equilibrium index of an array.

#include<iostream>
using namespace std;

int Equilibrium(int* , int);

int main()
{
    int arr[] = {-7,1,5,2,-4,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << Equilibrium(&arr[0] , n) << endl;

    return 0;
}

int Equilibrium(int arr[] , int n)
{
    int total=0 , Lsum=0;

    for(int i=0 ; i<n ; i++)
        total = total + arr[i];

    for(int i=0 ; i<n ; i++)
    {
        total = total - arr[i];

        if(total == Lsum)
            return i;

        Lsum = Lsum + arr[i];
    }
    return -1;
}

/* int Equilibrium(int arr[] , int n)
{
    for(int i=1 ; i<n-1 ; i++)
    {
        int sum1=0 , sum2=0;

        for(int j=0 ; j<i ; j++)
            sum1 = sum1 + arr[j];

        for(int k=i+1 ; k<n ; k++)
            sum2 = sum2 + arr[k];

        if(sum1 == sum2)
            return i;
    }
    return -1;
}
*/
