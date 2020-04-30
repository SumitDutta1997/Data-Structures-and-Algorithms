// find the number of triangles that can be formed with three different array elements
// as three sides of triangles, for a given unsorted array of n elements

#include<iostream>
#include<algorithm>
using namespace std;

int Triangles(int* , int);

int main()
{
    int arr[] = {4,6,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);

    cout << "Output : " << Triangles(&arr[0] , n) << endl;

    return 0;
}

int Triangles(int arr[] , int n)
{
    int count=0;
    for(int i=0 ; i<n-2 ; i++)
    {
        for(int j=i+1 ; j<n-1 ; j++)
        {
            for(int k=j+1 ; k<n ; k++)
            {
                if(arr[i]+arr[j]>arr[k] && arr[i]+arr[k]>arr[j] && arr[j]+arr[k]>arr[i])
                    //cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
                    count++;
            }
        }
    }
    return count;
}

/*
int Triangles(int arr[] , int n)
{
    int count=0;
    for(int i=0 ; i<n-2 ; i++)
    {
        int k = i+2;
        for(int j=i+1 ; j<n ; j++)
        {
            while(k<n && arr[i]+arr[j] > arr[k])
                k++;
            if(k>j)
                count += k-j-1;
        }
    }
    return count;
}
*/
