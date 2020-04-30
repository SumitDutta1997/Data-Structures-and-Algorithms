// lock and key problem

#include<iostream>
using namespace std;

void LockAndKey(char* , char* , int);

int main()
{
    char nuts[] =  {'@','#','$','%','^','&'};
    char bolts[] = {'$','%','&','^','@','#'};

    int n = sizeof(nuts)/sizeof(nuts[0]);

    LockAndKey(nuts , bolts , n);

    for(int i=0 ; i<n ; i++)
        cout << nuts[i] << " ";

    cout << endl;

    for(int i=0 ; i<n ; i++)
        cout << bolts[i] << " ";

    cout << endl;

    return 0;
}

void LockAndKey(char nuts[] , char bolts[] , int n)
{
    int size = n;
    while(size--)
    {
        int i=0;
        for(int j=0 ; j<n ; j++)
        {
            if(nuts[i] == bolts[j])
            {
                swap(nuts[i],nuts[j]);
                break;
            }
        }
    }
}
