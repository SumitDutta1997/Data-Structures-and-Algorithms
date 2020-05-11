// Remove duplicate from sorted linked list

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

void Duplicates(struct node *p)
{
    struct node *q = first->next;
    while(q!=NULL)
    {
        if(q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete(q);
            q = p->next;
        }
    }
}

int main()
{
    int A[] = {3,5,5,5,5,5,8,8,8,8};
    Create(A,10);

    Display(first);
    Duplicates(first);
    Display(first);

    return 0;
}
