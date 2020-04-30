// Check if two strings are Anagram (Hash Table)

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int len1 = strlen(A);
    int len2 = strlen(B);

    int i, H[26]={0};

    if(len1==len2)
    {
        for(i=0 ; A[i]!='\0' ; i++)
            H[A[i]-97] += 1;

        for(i=0 ; B[i]!='\0' ; i++)
        {
            H[B[i]-97] -= 1;

            if(H[B[i]-97] < 0)
            {
                cout << "Not Anagram" << endl;
                break;
            }
        }
        if(B[i] == '\0')
            cout << "Anagram" << endl;
    }
    else
        cout << "Not Anagram." << endl;

    return 0;
}


