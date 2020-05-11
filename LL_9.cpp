// Deleting a node from a Linked List (beginning , nth node and from end as well)

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

int Delete(struct node *p , int position)
{
    struct node *q = NULL;
    int x = -1;

    if(position < 1 || position > length(p))
    {
        cout << "Invalid node position" <<endl;
        return -1;
    }

    if(position == 1)
    {
        x = p->data;
        q = p;
        first = first->next;
        delete(q);
    }
    else
    {
        q = p;
        for(int i=1 ; i<position ; i++)
        {
            q=p;
            p = p->next;
        }
        if(p!=NULL)
        {
            q->next = p->next;
            x = p->data;
            delete(q);
        }
    }
    return x;
}

int main()
{
    int A[] = {5,7,9,13,15};
    Create(A,5);

    Display(first);
    cout << "Element deleted is " << Delete(first , 3) << endl;
    Display(first);
    cout << endl;

    return 0;
}
