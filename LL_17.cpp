// Check for loop in a linked list

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

void IsThereLoop(struct node *p)
{
    struct node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : NULL;
    }
    while(p!=NULL && q!=NULL && p!=q);

    if(p==q)
        cout << "Loop Found." << endl;
    else
        cout << "No loop found." << endl;
}

int main()
{
    struct node *t1 , *t2;
    int A[] = {5,7,9,13,15,11,21};
    Create(A,7);

    t1 = first->next->next->next;
    t2 = first->next->next->next->next->next->next;
    t2->next = t1;  // Comment this line and run

    IsThereLoop(first);

    return 0;
}
