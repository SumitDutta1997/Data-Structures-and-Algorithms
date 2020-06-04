// Implementing stack using linked list

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void Push(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL)
        cout << "Stack Overflow." << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop()
{
    int x=-1;
    struct node *p = top;
    if(top == NULL)
        cout << "Stack is empty." << endl;
    else
    {
        top = top->next;
        x = p->data;
        delete(p);
    }
    return x;
}

int Find(int pos)
{
    struct node *p=top;
    for(int i=1 ; p!=NULL && i<pos ; i++)
        p = p->next;
    if(p!=NULL)
        return p->data;
    else
        return -1;
}

int stackTop()
{
    if(top != NULL)
        return top->data;
    return -1;
}

int isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}

int isFull()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    int result = p ? 0 : 1;
    delete(p);
    return result;
}

void Display()
{
    struct node *p = top;
    cout << "Stack : ";
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Push(2);
    Push(4);
    Push(6);
    Display();
    cout << "Top of stack is : " << stackTop() << endl;
    cout << "First of stack is : " << Find(1) << endl;

    Pop();
    Display();
    cout << "Top of stack is : " << stackTop() << endl;
    cout << "First of stack is : " << Find(1) << endl;
    Pop();
    Display();
    cout << "Top of stack is : " << stackTop() << endl;
    cout << "First of stack is : " << Find(1) << endl;
    Pop();
    Display();
    cout << "Top of stack is : " << stackTop() << endl;
    cout << "First of stack is : " << Find(1) << endl;

    if(isEmpty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;

    if(isFull())
        cout << "Stack is full" << endl;
    else
        cout << "Stack is not full" << endl;

    return 0;
}
