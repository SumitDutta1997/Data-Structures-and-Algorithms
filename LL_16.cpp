// Merging Two linked list (combining two sorted LL into a single sorted LL)

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL , *second=NULL , *third=NULL;

void Create1(int A[] , int n)
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

void Create2(int A[] , int n)
{
    struct node *temp , *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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

void Merging(struct node *p , struct node *q)
{
    struct node *last = NULL;

    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p!=NULL)
        last->next = p;
    else
        last->next = q;
}

int main()
{
    int A[] = {2,8,10,15};
    int B[] = {4,7,12,14};

    Create1(A,4);
    Create2(B,4);

    Display(first);
    Display(second);

    cout << endl;
    Merging(first,second);
    Display(third);

    return 0;
}
