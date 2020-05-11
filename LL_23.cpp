// Reverse a doubly linked list.

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *first = NULL;

void DCreate(int A[] , int n)
{
    struct node *temp , *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1 ; i<n ; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        last->next = temp;
        temp->prev = last;
        temp->data = A[i];
        temp->next = NULL;
        last = temp;
    }
}

void DDisplay(struct node *p)
{
    cout << "Linked List : ";
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DReverse(struct node *p)
{
    struct node *t;
    while(p!=NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if(p!=NULL && p->next==NULL)
            first = p;
    }
    cout << endl;
}

int main()
{
    int A[] = {5,7,9,13,19,16};
    DCreate(A,6);

    DDisplay(first);
    DReverse(first);
    DDisplay(first);

    return 0;
}
