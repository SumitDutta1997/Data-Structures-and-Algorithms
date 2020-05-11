// Display a circular doubly linked list. Inserting in a circular doubly linked list

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void CDCreate(int A[] , int n)
{
    struct node *temp , *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->prev = head->next;
    head->data = A[0];
    head->next = head->prev;
    last = head;

    for(int i=1 ; i<n ; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        last->next = temp;
        temp->prev = last;
        temp->data = A[i];
        temp->next = head;
        head->prev = temp;
        last = temp;
    }
}

void CDDisplay(struct node *p)
{
    cout << "Linked List : ";
    do
    {
        cout << p->data << " ";
        p = p->next;
    }
    while(p!=head);
    cout << endl;
}

int length(struct node* p)
{
    int c=0;
    do
    {
        c++;
        p = p->next;
    }
    while(p!=head);
    return c;
}

void CDInserting(struct node *p , int position , int x)
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

        if(head == NULL)
        {
            head->next = head;
            head->prev = head;
            head = t;
        }
        else
        {
            t->next = head;
            t->prev = head->prev;
            head->prev->next = t;
            t->prev = t;
            head = t;
        }
    }
    else
    {
        for(int i=1 ; i<position-1 ; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next = t;
        t->next->prev = t;
    }
}

int main()
{
    int A[] = {5,7,9,13,19,16};
    CDCreate(A,6);

    CDDisplay(head);
    CDInserting(head , 1 , 88);
    CDDisplay(head);

    return 0;
}
