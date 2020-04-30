// find the sum of bit difference in all pairs that can be formed in an array.

#include<iostream>
using namespace std;

int BitDifference(int* , int);

int main()
{
    int arr[] = {1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << BitDifference(&arr[0] , n);

    return 0;
}

int BitDifference(int arr[] , int n)
{
    int count=0;
    for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i == j)
                continue;
			if(arr[i] == arr[j])
                continue;

            int x = arr[i];
			int y = arr[j];

			while(x && y)
			{
				if((x & 1) != (y & 1))
                    count++;

				x = x >> 1;
				y = y >> 1;
			}

			if(x)
                while(x)
                {
                    count += ((x&1)^0);
                    x = x >> 1;
                }
			if(y)
                while(y)
                {
                    count += ((y&1)^0);
                    y = y >> 1;
                }
		}
	}
	return count;
}
