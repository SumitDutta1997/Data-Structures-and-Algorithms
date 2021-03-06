// Implementing a circular queue using array

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q , int size)
{
    q->size = size;
    q->Q = (int *)malloc(q->size*sizeof(int));
    q->rear = q->front = 0;
}

void enqueue(struct Queue *q , int x)
{
    if((q->rear+1)%q->size == q->front)
        cout << "Queue is Full." << endl;
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
        cout << "Queue is empty." << endl;
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    cout << "Queue : ";
    int i = q.front+1;
    do
    {
        cout << q.Q[i] << " ";
        i=(i+1)%q.size;
    }
    while(i!=(q.rear+1)%q.size);
    cout << endl;
}

bool isEmpty(struct Queue q)
{
    if(q.front == q.rear)
        return true;
    return false;
}

bool isFull(struct Queue q)
{
    return (q.rear+1)%q.size==q.front ? true : false;
}

int main()
{
    struct Queue q;
    Create(&q , 5);

    enqueue(&q , 4);
    enqueue(&q , 5);
    enqueue(&q , 9);
    enqueue(&q , 11);
    //enqueue(&q , 13);

   // cout << "Deleted element is : " << dequeue(&q) << endl;

    Display(q);

    if(isEmpty(q))
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    if(isFull(q))
        cout << "Queue is full." << endl;
    else
        cout << "Queue is not full." << endl;

    return 0;
}
