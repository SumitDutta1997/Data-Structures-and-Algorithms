// Inserting in a Linked List (beginning , anywhere middle and end)

#include<iostream>
#include<stdlib.h>
using namespace std;

void Create(int , int );
void Insert(struct node* , int , int);
void Display(struct node*);
int length(struct node*);

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

void Insert(struct node *p , int position , int x)
{
    struct node *t;

    if(position < 1 || position > (length(p)+1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(position == 1)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(position > 1)
    {
        for(int i=0 ; i<position-2 ; i++)
            p = p->next;
        if(p!=NULL)
        {
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
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

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);

    Display(first);
    Insert(first , 4 , 89);
    cout << endl;
    Display(first);

    return 0;
}

