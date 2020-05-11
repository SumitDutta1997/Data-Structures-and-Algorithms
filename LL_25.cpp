// Finding middle node of a linked list.

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

int Middle(struct node *p)
{
    struct node *q = p;
    while(q!=NULL)
    {
        q = q->next;
        if(q!=NULL)
            q = q->next;
        if(q!=NULL)
            p = p->next;
    }
    return p->data;
}

int main()
{
    int A[] = {9,10,15,1,2,3,4};
    Create(A,7);

    Display(first);
    cout << "Middle node of the linked list is : " << Middle(first) << endl;

    return 0;
}
