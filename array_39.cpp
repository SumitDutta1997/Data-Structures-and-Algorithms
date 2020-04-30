// Jumping numbers GFG

#include<iostream>
using namespace std;

void print_jumping(int a,int i)
{
    if(i>a)
        return;

    cout<<i<<" ";

    if(i%10==9)
    {
        print_jumping(a,i*10+8);
    }

    else if(i%10==0)
    {
        print_jumping(a,i*10+1);
    }

    else
    {
        int temp=i%10;
        print_jumping(a,i*10+(temp-1));
        print_jumping(a,i*10+(temp+1));
    }
}

void print(int a)
{
    cout << "0" << " ";

    for(int i=1 ; i<10 ; i++)
        print_jumping(a,i);
}

int main()
{
  print(200);
}
