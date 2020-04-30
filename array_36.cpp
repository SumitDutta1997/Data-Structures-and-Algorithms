// Traverse a matrix of integers in spiral form

#include<iostream>
using namespace std;

#define R 3
#define C 6

void SpiralTraversing(int matrix[R][C] , int , int);

int main()
{
    int matrix[R][C] =
    {
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18}
    };

    SpiralTraversing(matrix , R , C);

    return 0;
}

void SpiralTraversing(int matrix[R][C] , int m , int n)
{
    int i, k=0, l=0;

    while(k<m && l<n)
    {
        for(i=l ; i<n ; i++)
        {
            cout << matrix[k][i] << " ";
        }
        k++;

        for(i=k ; i<m ; i++)
        {
            cout << matrix[i][n-1] << " ";
        }
        n--;

        if(k<m)
        {
            for(i=n-1 ; i>=l ; i--)
            {
                cout << matrix[m-1][i] << " ";
            }
            m--;
        }

        if(l<n)
        {
            for(i=m-1 ; i>=k ; i--)
            {
                cout << matrix[i][l] << " ";
            }
            l++;
        }
    }
}
