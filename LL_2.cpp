// Counting nodes in a linked list (2) using Recursion as well.

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL;

void Create(int A[] , int n)
{
    struct node *temp , *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1 ; i<n ; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Count(struct node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p = p->next;
    }
    cout << "Number of nodes are : " << c << endl;
}

int RCount(struct node *p)
{
    if(p==NULL)
        return 0;
    else
        return RCount(p->next) + 1;
}

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);

    Count(first);
    cout << "Number of nodes are : " << RCount(first) << endl;

    return 0;
}


