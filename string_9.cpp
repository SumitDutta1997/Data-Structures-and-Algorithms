// String is Palindrome or not

#include<iostream>
using namespace std;

int main()
{
   char A[] = "MADAM";
   int i,j,flag=0;
   for(j=0 ; A[j] != '\0' ; j++)
   {}
   j=j-1;
   char B[j+2];

   for(i=0 ; j>=0 ; i++ , j--)
   {
       B[i] = A[j];
   }
   B[i] = '\0';

   for(i=0 ,j=0 ; A[i] != '\0' ; i++ , j++)
   {
       if(A[i] != B[j])
       {
           flag = 1;
           break;
       }
   }
   if(flag)
        cout << "not palindrome" << endl;
   else
        cout << "palindrome" << endl;

   return 0;
}

