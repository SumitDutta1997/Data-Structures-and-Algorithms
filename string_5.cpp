// Validating a string

#include<iostream>
using namespace std;

int validate(char *);

int main()
{
    char A[] = "Ani?321";

    if(validate(A))
        cout << "valid string" << endl;
    else
        cout << "invalid string" << endl;

    return 0;
}

int validate(char A[])
{
    for(int i=0 ; A[i] != '\0' ; i++)
    {
        if(!(A[i] >= 65 && A[i] <= 90) &&
        !(A[i] >= 97 && A[i] <= 122) &&
        !(A[i] >= 48 && A[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

