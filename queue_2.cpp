// Implementing queue using linked list

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;

void Enqueue(int x)
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
    if(t==NULL)
        cout << "Queue is empty." << endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue()
{
    int x=-1;
    struct Queue *p;
    if(front == NULL)
        cout << "Queue is empty." << endl;
    else
    {
        p = front;
        front  = front->next;
        x = p->data;
        delete(p);
    }
    return x;
}

bool isEmpty()
{
    if(front == NULL)
        return true;
    return false;
}

bool isFull()
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
    if(t==NULL)
        return true;
    return false;
}

void Display()
{
    cout << "Queue : ";
    struct Queue *p=front;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Enqueue(4);
    //Enqueue(6);
    //Enqueue(8);

    cout << "Element deleted is : " << Dequeue() << endl;

    Display();

    if(isEmpty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    if(isFull())
        cout << "Queue is full." << endl;
    else
        cout << "Queue is not full." << endl;

    return 0;
}

