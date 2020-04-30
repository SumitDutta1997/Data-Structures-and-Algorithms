// Searching in a linked list (2) using recursion as well.

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

int Search(struct node *p , int key)
{
    while(p!=NULL)
    {
        if(key == p->data)
            return 1;
        p = p->next;
    }
    return 0;
}

int RSearch(struct node *p , int key)
{
    if(p == NULL)
        return 0;
    else if(key == p->data)
        return 1;
    else
        return RSearch(p->next , key);
}

int main()
{
    int A[] = {5,7,9,10,15};
    Create(A,5);

    if(Search(first , 15))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;


    RSearch(first , 5) ? cout << "Element found." : cout << "Element not found.";
    cout << endl;

    return 0;
}
