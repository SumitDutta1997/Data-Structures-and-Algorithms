// find common element in given three sorted arrays

#include<iostream>
using namespace std;

void CommonElement(int* , int* , int* , int, int , int);

int main()
{
    int arr1[] = {1,5,10,20,40,80};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {6,7,20,80,100};
    int m = sizeof(arr2)/sizeof(arr2[0]);

    int arr3[] = {3,4,15,20,30,70,80,120};
    int o = sizeof(arr3)/sizeof(arr3[0]);

    CommonElement(&arr1[0] , &arr2[0] , &arr3[0] , n , m , o);

    return 0;
}

void CommonElement(int arr1[] , int arr2[] , int arr3[] , int n , int m , int o)
{
    int i=0 , j=0 , k=0;
    while(i<n && j<m && k<o)
    {
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            cout << arr1[i] << " ";
            i++; j++; k++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else if(arr2[j] < arr3[k])
            j++;
        else
            k++;
    }
}
