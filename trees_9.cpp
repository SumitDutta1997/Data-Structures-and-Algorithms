// Deleting a node from a BST

#include<iostream>
#include<stdlib.h>
using namespace std;

int Height(struct node *);
struct node *InPre(struct node *);
struct node *InSucc(struct node *);

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

struct node *DeleteBST(struct node *p , int value)
{
    struct node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p==root)
            root = NULL;
        delete(p);
        return NULL;
    }
    if(value < p->data)
        p->lchild = DeleteBST(p->lchild , value);
    else if(value > p->data)
        p->rchild = DeleteBST(p->rchild , value);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = DeleteBST(p->lchild , q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = DeleteBST(p->rchild , q->data);
        }
    }
}

int Height(struct node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return x>y ? x+1 : y+1;
}

struct node *InPre(struct node *p)
{
    while(p!=NULL && p->rchild!=NULL)
        p = p->rchild;
    return p;
}

struct node *InSucc(struct node *p)
{
    while(p!=NULL && p->lchild!=NULL)
        p = p->lchild;
    return p;
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

int main()
{
    IterativeInsert(30);
    IterativeInsert(20);
    IterativeInsert(40);
    IterativeInsert(10);
    IterativeInsert(25);
    IterativeInsert(35);
    IterativeInsert(45);

    Inorder(root);
    cout << endl;

    if(SearchBST(30))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    cout << endl;
    DeleteBST(root,30);
    Inorder(root);
    cout << endl;

    if(SearchBST(30))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
