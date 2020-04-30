// number occurring odd no. of times

#include<iostream>
using namespace std;

void OddNumberOfTimes(int* , int);

int main()
{
    int arr[] = {1,2,3,2,3,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    OddNumberOfTimes(&arr[0] , n);

    return 0;
}

void OddNumberOfTimes(int arr[] , int n)
{
    int flag = 0 , value = 0;
    for(int i=0 ; i<n ; i++)
    {
        int count = 0;
        for(int j=0 ; j<n ; j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if(count%2 != 0)
        {
            flag = 1;
            value = arr[i];
            break;
        }
    }
    if(flag == 1)
        cout << "Number is : " << value << endl;
    else
        cout << "None." << endl;
}

/* //  bitwise XOR Solution
int OddNumberOfTimes(int arr[] , int n)
{
    int result = 0;
    for(int i=0 ; i<n ; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}
*/
