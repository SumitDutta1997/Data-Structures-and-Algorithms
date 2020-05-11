// Deleting from a doubly linked list.

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

int DDeleting(struct node *p , int position)
{
    int x = -1;
    if(position < 1 || position > length(p))
    {
        cout << "Invalid position" << endl;
        return -1;
    }
    if(position == 1)
    {
        first = first->next;
        x = p->data;
        delete(p);
        if(first!=NULL)
            first->prev = NULL;
    }
    else
    {
        for(int i=1 ; i<=position-1 ; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next!=NULL)
            p->next->prev = p->prev;
        x = p->data;
        delete(p);
    }
    return x;
}

int main()
{
    int A[] = {5,7,9,13,19,16};
    DCreate(A,6);

    DDisplay(first);
    cout << "Deleted element is : " << DDeleting(first , 4) << endl;
    DDisplay(first);

    return 0;
}


