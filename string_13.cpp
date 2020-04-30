// Finding duplicates in a string (using Bitwise Operation)

#include<iostream>
using namespace std;

int main()
{
    char A[] = "findings";
    long int H=0 , x=0;

    for(int i=0 ; A[i]!='\0' ; i++)
    {
        x=1;
        x = x << A[i]-97;
        int sumit = x&H;

        if(sumit > 0)
            cout << A[i] << " is duplicate." << endl;
        else
            H = x|H;
    }

    return 0;
}


