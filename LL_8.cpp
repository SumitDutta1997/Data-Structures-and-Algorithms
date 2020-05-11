// Inserting in a Sorted Linked List

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

void SortedInsert(struct node *p , int x)
{
    struct node *t , *q;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    q=NULL;
    if(first == NULL)
        first = t;
    else
    {
        while(p!=NULL && x > p->data)
        {
            q=p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {5,7,9,13,15};
    Create(A,5);

    Display(first);
    SortedInsert(first , 3);
    Display(first);

    return 0;
}
