// Changing upper case to lower case and vice versa

#include<iostream>
using namespace std;

int main()
{
    char A[] = "WELCOME";
    for(int i=0 ; A[i] != '\0' ; i++)
    {
        if(A[i]>=65 && A[i]<=90)
            A[i] += 32;
        else if(A[i]>=97 && A[i]<=122)
            A[i] -= 32;

    }
    cout << A << endl;

    return 0;
}
