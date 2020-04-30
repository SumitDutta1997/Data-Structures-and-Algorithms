// Finding duplicates in a string (comparing)

#include<iostream>
using namespace std;

int main()
{
    char A[] = "geeksforgeeks";
    int i,j,flag;
    for(i=0 ; A[i]!='\0' ; i++)
    {
        flag=0;
        if(A[i] != -1)
        {
            for(j=i+1 ; A[j]!='\0' ; j++)
            {
                if(A[i] == A[j])
                {
                    flag++;
                    A[j] = -1;
                }
            }
            if(flag)
                cout << A[i] << endl;
        }
    }

    return 0;
}
