// find the contiguous sub-array with maximum sum in an array
// of positive and negative numbers.

#include<iostream>
using namespace std;

int MaxSubArray(int* , int);

int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Maximum contiguous sum is : " << MaxSubArray(&arr[0] , n) << endl;

    return 0;
}

int MaxSubArray(int arr[] , int n)
{
    int maxSum=0 , sum=0;
    int start=0 , end=0 , s=0;
    for(int i=0 ; i<n ; i++)
    {
        sum = sum + arr[i];
        if(sum < 0)
        {
            sum=0;
            s = i+1;
        }
        else if(maxSum < sum)
        {
            maxSum = sum;
            start = s;
            end = i;
        }
    }
    cout << "Start index: " << start << endl << "End index: " << end << endl;
    return maxSum;
}
