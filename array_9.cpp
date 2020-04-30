// union and intersection

#include<iostream>
using namespace std;

void Union(int* , int* , int , int);
void Intersection(int* , int* , int , int);

int main()
{
    int arr1[] = {2,3,4,6};
    int arr2[] = {1,3,5,6,11,13};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    Union(&arr1[0] , &arr2[0] , n , m);
    Intersection(&arr1[0] , &arr2[0] , n , m);

    return 0;
}

void Union(int arr1[] , int arr2[] , int n , int m)
{
    cout << "Union : ";
    int i=0 , j=0 ;

    while(i<n && j<m)
    {
        if(arr1[i] < arr2[j])
            cout << arr1[i++] << " ";

        else if(arr1[i] > arr2[j])
            cout << arr2[j++] << " ";

        else {
            cout << arr1[i++] << " ";
            j++;
        }
    }

    while(i<n)
        cout << arr1[i++] << " ";

    while(j<m)
        cout << arr2[j++] << " ";

    cout << endl << endl;
}

void Intersection(int arr1[] , int arr2[] , int n , int m)
{
    cout << "Intersection : ";
    int i=0 , j=0;

    while(i<n && j<m)
    {
        if(arr1[i] < arr2[j])
            i++;

        else if(arr1[i] > arr2[j])
            j++;

        else {
            cout << arr1[i++] << " ";
            j++;
        }
    }
    cout << endl;
}

