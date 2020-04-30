// String is Palindrome or not (improvement)

#include<iostream>
using namespace std;

int main()
{
    char A[] = "MADAM";
    int i,j,flag=0;

    for(i=0 ; A[i]!='\0' ; i++)
    {}
    i=i-1;

    for(j=0 ; j<i ; i-- , j++)
    {
        if(A[i] != A[j])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        cout << "not palindrome" << endl;
    else
        cout << "palindrome" << endl;

    return 0;
}
