// Inserting in a circular linked list

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void Create(int A[] , int n)
{
    struct node *temp , *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i=1 ; i<n ; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

void CDisplay(struct node *p)
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

void Inserting(struct node *p , int position , int x)
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
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(int i=1 ; i< position-1 ; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {5,7,9,13,15};
    Create(A,5);

    CDisplay(head);
    Inserting(head,4,99);
    CDisplay(head);

    return 0;
}
