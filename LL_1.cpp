// Display a linked list using iteration and Recursion

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

void RDisplay(struct node *p)
{
    if(p!=NULL)
    {
        cout << p->data << " ";
        RDisplay(p->next);
    }
}

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);
    Display(first);

    cout << "Linked List : ";
    RDisplay(first);

    return 0;
}


