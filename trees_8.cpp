// Searching in a BST (Iterative and Recursive)

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

void Inorder(struct node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

int SearchBST(int value)
{
    struct node *p = root;
    while(p!=NULL)
    {
        if(value == p->data)
            return 1;
        else if(value < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return 0;
}

int RSearchBST(struct node *p , int value)
{
    if(p==NULL)
        return 0;
    if(value == p->data)
        return 1;
    else if(value < p->data)
        RSearchBST(p->lchild , value);
    else
        RSearchBST(p->rchild , value);
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

    if(SearchBST(35))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    if(RSearchBST(root,15))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}


