// Check if two strings are Anagram

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char A[] = "decimal";
    char B[] = "medical";

    int len1 = strlen(A);
    int len2 = strlen(B);

    if(len1==len2)
    {
        int flag=0;
        for(int i=0 ; i<len1 ; i++)
        {
            int found=0;
            for(int j=0 ; j<len2 ; j++)
            {
                if(A[i] == B[j])
                {
                    found=1;
                    break;
                }
            }
            if(found==0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout << "Not Anagram" << endl;
        else
            cout << "Anagram" << endl;
    }
    else
        cout << "Not Anagram." << endl;

    return 0;
}

