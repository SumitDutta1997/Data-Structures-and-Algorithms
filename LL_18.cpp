// Display a circular linked list (1) iteratively (2) using recursion

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

void RCDisplay(struct node *p)
{
    static int flag = 0;
    if(p!=head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        RCDisplay(p->next);
    }
}

int main()
{
    int A[] = {5,7,9,13,15};
    Create(A,5);

    CDisplay(head);
    cout << "Linked List : ";
    RCDisplay(head);

    return 0;
}

