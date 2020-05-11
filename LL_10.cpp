// Deleting the given key (if present) from a linked list

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

void DeleteKey(int key)
{
    struct node *p = first;
    struct node *q = NULL;

    if(p!=NULL && p->data == key)
    {
        first = p->next;
        delete(p);
        return;
    }
    else
    {
         while(p!=NULL && p->data != key)
         {
             q = p;
             p = p->next;
         }

         if(p==NULL)
         {
            cout << "Key not found" << endl << endl;
            return;
         }

         if(p!=NULL)
         {
             q->next = p->next;
             delete(p);
         }
    }
}

int main()
{
    int A[] = {5,7,9,13,15};
    Create(A,5);

    Display(first);
    DeleteKey(13);
    Display(first);

    return 0;
}

