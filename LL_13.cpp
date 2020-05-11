// Reversing a linked list (1) Reversing Elements (2) Reversing links(more preferable)

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

void ReversingElements(struct node *p)
{
    int l = length(p);
    int A[l];
    int i=0;
    while(p!=NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first; i--;

    while(p!=NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}

void ReversingLinks(struct node *p)
{
    struct node *q=NULL , *r=NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    int A[] = {3,5,9,12,15,7};
    Create(A,6);

    Display(first);
    ReversingElements(first);
    Display(first);
    ReversingLinks(first);
    Display(first);

    return 0;
}

