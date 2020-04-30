// find minimum number of platforms required for the railway station
// so that no train waits according to arrival and departure time.

#include<iostream>
#include<algorithm>
using namespace std;

int Platforms(int* , int* , int);

int main()
{
    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1120,1130,1200,1900,2000};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Minimum number of platforms required = " << Platforms(&arr[0] , &dep[0] , n) << endl;

    return 0;
}

int Platforms(int arr[] , int dep[] , int n)
{
    sort(arr , arr+n);
    sort(dep , dep+n);

    int count=0 , result=0;
    int i=0 , j=0;

    while(i<n && j<n)
    {
        if(arr[i] <= dep[j])
        {
            count++;
            i++;
            if(result < count)
                result = count;
        }
        else
        {
            count--;
            j++;
        }
    }
    return result;
}
