// concatenating two linked list

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL , *second=NULL , *third = NULL;

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

void concatenate(struct node *p , struct node *q)
{
    third = p;
    while(p->next!=NULL)
        p = p->next;
    p->next = q;
}

int main()
{
    int A[] = {3,5,9,12,15,7};
    int B[] = {1,2,3,4,5};

    Create1(A,6);
    Create2(B,5);

    Display(first);
    Display(second);

    concatenate(first,second);
    Display(third);

    return 0;
}
