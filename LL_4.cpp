// Max element in a linked list (2) using Recursion as well.

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

int Max(struct node *p)
{
    int maximum = -32768;  // MIN_INT
    while(p!=NULL)
    {
        if(p->data > maximum)
            maximum = p->data;
        p = p->next;
    }
    return maximum;
}

int RMax(struct node *p)
{
    int m = 0;
    if(p == NULL)
        return 0;
    else
    {
        m = RMax(p->next);
        if(m > p->data)
            return m;
        else
            return p->data;
    }
}

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);

    cout << "Max element in this linked list is : " << Max(first) << endl;
    cout << "Max element in this linked list is : " << RMax(first) << endl;

    return 0;
}




