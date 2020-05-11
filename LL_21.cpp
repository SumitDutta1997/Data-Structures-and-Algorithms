// Display a doubly linked list. Inserting in a doubly linked list.

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

int length(struct node* p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void DInserting(struct node *p , int position , int x)
{
    struct node *t;
    if(position < 1 || position > length(p)+1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(position == 1)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        if(first!=NULL)
            first->prev = t;
        first = t;
    }
    else
    {
        for(int i=1 ; i<position-1 ; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next!=NULL)
            p->next->prev = t;
        p->next = t;
    }
}

int main()
{
    int A[] = {5,7,9,13,19,16};
    DCreate(A,6);

    DDisplay(first);
    DInserting(first , 4 , 88);
    DDisplay(first);

    return 0;
}

