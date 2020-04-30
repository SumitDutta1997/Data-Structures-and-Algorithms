// Permutation of a string (Swapping) (In Place)

#include<iostream>
#include<string.h>
using namespace std;

void Perm(char* , int , int);

int main()
{
    char S[] = "abc";
    int l = 0;
    int h = strlen(S)-1;

    Perm(S,l,h);

    return 0;
}

void Perm(char S[] , int l , int h)
{
    int i;
    if(l==h)
    {
        for(i=0 ; S[i]!='\0' ; i++)
            cout << S[i];
        cout << endl;
    }
    else
    {
        for(i=l ; i<=h ; i++)
        {
            swap(S[l] , S[i]);
            Perm(S , l+1 , h);
            swap(S[l] , S[i]);
        }
    }
}
