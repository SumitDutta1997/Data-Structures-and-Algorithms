// find the largest subarray with equal numbers of 0's and 1's

#include<iostream>
using namespace std;

void LargestSubarray(int* , int);

int main()
{
    int arr[] = {0,0,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    LargestSubarray(&arr[0] , n);

    return 0;
}

void LargestSubarray(int arr[] , int n)
{
    int diff=0 , first=0 , last=0 , flag=0;
    for(int i=0 ; i<n-1 ; i++)
    {
        int countOne=0 , countZero=0;
        for(int j=i ; j<n ; j++)
        {
            (arr[j] == 1) ? countOne++ : countZero++;
            if(countOne == countZero && diff < j-i)
            {
                flag = 1;
                diff = j-i;
                first=i ; last=j ;
            }
        }
    }
    if(flag)
        cout << first << " to " << last << endl;
    else
        cout << "No subarray found!" << endl;
}
