// Longest span with same sum in two binary arrays (naive approach)

#include<iostream>
using namespace std;

int longestCommonSum(int* , int* , int);

int main()
{
    int arr1[] = {0,1,0,1,1,1,1,0,1};
    int arr2[] = {1,1,1,1,1,0,1,1,0};

    int n = sizeof(arr1)/sizeof(arr1[0]);

    cout << "Length of the longest common span with same sum is : " << longestCommonSum(&arr1[0] , &arr2[0] , n) << endl;

    return 0;
}


int longestCommonSum(int arr1[] , int arr2[] , int n)
{
    int maxLen = 0;
    for(int i=0 ; i<n ; i++)
    {
        int sum1 = 0 , sum2 = 0;
        for(int j=i ; j<n ; j++)
        {
            sum1 = sum1 + arr1[j];
            sum2 = sum2 + arr2[j];
                if(sum1 == sum2)
                {
                    int len = (j+1)-i;
                    if(maxLen < len)
                        maxLen = len;
                }
        }
    }
    return maxLen;
}
