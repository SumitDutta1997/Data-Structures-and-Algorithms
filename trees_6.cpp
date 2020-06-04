// Count leaf node of a binary tree

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

int LeafCount(struct node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = LeafCount(p->lchild);
        y = LeafCount(p->rchild);

        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int main()
{

    CreateBinaryTree();

    cout << endl;
    cout << "Number of Leaf nodes in this binary tree are : " << LeafCount(root) << endl;

    return 0;
}



