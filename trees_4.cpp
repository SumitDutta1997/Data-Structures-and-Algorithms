// Count number of nodes in a binary tree

#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *root = NULL;

void CreateBinaryTree()
{
    struct node *p , *t;
    int x;
    queue<struct node *>q;
    cout << "Enter root node : ";
    cin >> x;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p->data << " : ";
        cin >> x;
        if(x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter right child of " << p->data << " : ";
        cin >> x;
        if(x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

int Count(struct node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int main()
{

    CreateBinaryTree();

    cout << endl;
    cout << "Number of nodes in this binary tree are : " << Count(root) << endl;

    return 0;
}

