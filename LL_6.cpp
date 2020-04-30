// Improving Linear Search (Move to head)

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

LSearch(struct node *p , int key)
{
    struct node *q = NULL;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            if(p == first)
                return 1;
            else
            {
                q->next = p->next;
                p->next = first;
                first = p;
                return 1;
            }
        }
        q=p;
        p = p->next;
    }
    return 0;
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

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);

    Display(first);

    if(LSearch(first , 10))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    Display(first);

    return 0;
}

