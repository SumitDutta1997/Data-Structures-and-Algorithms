// Comparing strings

#include<iostream>
using namespace std;

int main()
{
   char A[] = "Painter";
   char B[] = "Painting";

   int i,j;
   for(i=0,j=0 ; A[i]!='\0' && B[i]!='\0' ; i++,j++)
   {
       if(A[i] != B[j])
           break;
   }

   if(A[i] == B[j])
        cout << "Equal" << endl;
    else if(A[i] < B[j])
        cout << "Smaller" << endl;
    else
        cout << "Greater" << endl;

   return 0;
}
