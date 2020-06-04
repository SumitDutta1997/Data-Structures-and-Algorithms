// Implementation of stack using array

#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack
{
    int top;
    int size;
    int *S;
};

void Create(struct stack *st)
{
    cout << "Enter the size of stack : ";
    cin >> st->size;
    st->S = (int *)malloc(st->size*sizeof(int));
    st->top = -1;
}

void Push(struct stack *st , int x)
{
    if(st->top == st->size-1)
        cout << "stack overflow." << endl;
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(struct stack *st)
{
    int x=-1;
    if(st->top == -1)
        cout << "stack empty." << endl;
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int Find(struct stack st , int pos)
{
    int x=-1;
    if(pos <= 0 || pos > st.size)
        cout << "Invalid position.";
    else
        x = st.S[st.top-pos+1];

    return x;
}

int stackTop(struct stack st)
{
    if(st.top == -1)
        return -1;
    else
        return st.S[st.top];
}

bool isEmpty(struct stack st)
{
    if(st.top == -1)
        return true;
    return false;
}

bool isFull(struct stack st)
{
    return st.top == st.size-1 ? true : false;
}

void Display(struct stack st)
{
    cout << "Stack : ";
    for(int i=st.top ; i>=0 ; i--)
        cout << st.S[i] << " ";

    cout << endl;
}

int main()
{
    struct stack st;

    // Testing
    Create(&st);
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;

    Push(&st , 10);
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "First element is : " << Find(st , 1) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;

    Push(&st , 20);
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "First element is : " << Find(st , 1) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;

    Push(&st , 30);
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;

    cout << "Deleted element is : " << Pop(&st) << endl;
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;

    cout << "Deleted element is : " << Pop(&st) << endl;
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;

    cout << "Deleted element is : " << Pop(&st) << endl;
    Display(st);
    cout << "stack top is : " << stackTop(st) << endl;
    cout << "Is the stack empty : " << isEmpty(st) << endl;
    cout << "Is the stack full : " << isFull(st) << endl;
    cout << endl;
}
