// Check if a linked list if sorted or not

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

int isSorted(struct node *p)
{
    int x = -32768;
    while(p!=NULL)
    {
        if(x <= p->data)
        {
            x = p->data;
            p = p->next;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    int A[] = {3,5,9,13,15};
    Create(A,5);

    isSorted(first) ? cout << "Sorted" : cout << "Not Sorted";

    return 0;
}


