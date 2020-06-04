// Creating a Binary Search Tree (BST) using Iterative Insert and Recursive Insert

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *root = NULL;

void IterativeInsert(int key)
{
    struct node *p , *tail=NULL;

    if(root == NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    struct node *t=root;

    while(t!=NULL)
    {
        tail = t;
        if(key == t->data)
            return;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = (struct node*)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(p->data < tail->data)
        tail->lchild = p;
    else
        tail->rchild = p;
}

struct node *RecursiveInsert(struct node *p , int key)
{
    struct node *t;
    if(p==NULL)
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RecursiveInsert(p->lchild , key);
    else if(key > p->data)
        p->rchild = RecursiveInsert(p->rchild , key);
    else
        return p;
}

void Inorder(struct node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

int main()
{
    IterativeInsert(30);
    IterativeInsert(20);
    IterativeInsert(40);
    IterativeInsert(10);
    IterativeInsert(25);
    IterativeInsert(35);
    IterativeInsert(50);
    Inorder(root);
    cout << endl;

    root = RecursiveInsert(root,30);
    RecursiveInsert(root,20);
    RecursiveInsert(root,40);
    RecursiveInsert(root,10);
    RecursiveInsert(root,25);
    RecursiveInsert(root,35);
    RecursiveInsert(root,50);
    Inorder(root);

    return 0;
}

