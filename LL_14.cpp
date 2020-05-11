// Reversing a linked list using recursion

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

void Display(struct node *p)
{
    cout << "Linked List : ";
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RecursiveReverse(struct node *q , struct node *p)
{
    if(p!=NULL)
    {
        RecursiveReverse(p , p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int A[] = {3,5,9,12,15,7};
    Create(A,6);

    Display(first);
    RecursiveReverse(NULL,first);
    Display(first);

    return 0;
}
