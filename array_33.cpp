// Rotate 2-D array

#include<iostream>
using namespace std;
#define N 4

void RotateMatrix(int matrix[N][N]);
void DisplayMatrix(int matrix[N][N]);

int main()
{
    int matrix[N][N] =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    RotateMatrix(matrix);
    DisplayMatrix(matrix);

    return 0;
}

void RotateMatrix(int matrix[N][N])
{
    for(int i=0 ; i<N/2 ; i++)
    {
        for(int j=i ; j<N-i-1 ; j++)
        {
            int temp             = matrix[i][j];
            matrix[i][j]         = matrix[j][N-1-i];
            matrix[j][N-i-1]     = matrix[N-i-1][N-j-1];
            matrix[N-i-1][N-j-1] = matrix[N-j-1][i];
            matrix[N-j-1][i]     = temp;
        }
    }
}

void DisplayMatrix(int matrix[N][N])
{
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
