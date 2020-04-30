// Sum of all elements in a linked list (2) using Recursion as well.

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

void Sum(struct node *p)
{
    int add=0;
    while(p!=NULL)
    {
        add = add + p->data;
        p = p->next;
    }
    cout << "Sum of all the elements in the linked list is : " << add << endl;
}

int RSum(struct node *p)
{
    if(p==NULL)
        return 0;
    else
        return RSum(p->next) + p->data;
}

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);

    Sum(first);
    cout << "Sum of all the elements in the linked list is : " << RSum(first) << endl;

    return 0;
}



