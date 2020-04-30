// majority element

#include<iostream>
using namespace std;

void MajorityElement(int* , int);

int main()
{
    int arr[] = {1,2,5,3,4,5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    MajorityElement(&arr[0] , n);

    return 0;
}

void MajorityElement(int arr[] , int n)
{
    int flag = 0 , value = 0;
    for(int i=0 ; i<n ; i++)
    {
        int count = 0;
        for(int j=i ; j<n ; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count > n/2)
        {
            flag = 1;
            value = arr[i];
            break;
        }
    }
    if(flag == 1)
        cout << "majority element : " << value << endl;
    else
        cout << "None." << endl;
}
