// counting words in a string

#include<iostream>
using namespace std;

int main()
{
    char A[] = "My name is Sumit   Dutta";
    int word=0;
    for(int i=0 ; A[i]!='\0' ; i++)
    {
        if(A[i] == ' ' && A[i-1] != ' ')
            word++;
    }
    cout << word+1 << endl;

    return 0;
}
