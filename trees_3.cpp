// Creating binary tree (using queue)
// Level Order Traversal

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

void LevelOrder(struct node *p)
{
    queue<struct node *>q;
    cout << p->data << " ";
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild)
        {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
}

int main()
{

    CreateBinaryTree();

    cout << endl;
    cout << "Level Order Traversal : ";
    LevelOrder(root);
    cout << endl;

    return 0;
}
