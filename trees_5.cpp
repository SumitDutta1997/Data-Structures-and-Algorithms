// Height of a binary tree

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

int Height(struct node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = Height(p->lchild);
        y = Height(p->rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int main()
{

    CreateBinaryTree();

    cout << endl;
    cout << "Height of this binary tree is : " << Height(root) << endl;

    return 0;
}


