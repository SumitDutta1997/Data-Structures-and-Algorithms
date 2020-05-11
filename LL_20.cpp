// Deleting from circular linked list

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

int Deleting(struct node *p , int position)
{
    struct node *q;
    int x=0;
    if(position < 1 || position > length(p))
    {
        cout << "Invalid position" << endl;
        return -1;
    }
    if(position == 1)
    {
        while(p->next!=head)
            p = p->next;
        x = head->data;
        if(p == head)
        {
            delete(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete(head);
            head = head->next;
        }
    }
    else
    {
        for(int i=1 ; i<position-1 ; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete(q);
    }
    return x;
}

int main()
{
    int A[] = {5,7,9,13,15};
    Create(A,5);

    CDisplay(head);
    cout << "Deleted element is : " << Deleting(head,3) << endl;
    CDisplay(head);

    return 0;
}
