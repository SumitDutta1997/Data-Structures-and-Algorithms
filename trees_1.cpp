// Creating binary tree (using queue)
// Preorder , Inorder , Postorder Traversals (Recursive)

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

void PreOrder(struct node *p)
{
    if(p != NULL)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(struct node *p)
{
    if(p != NULL)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void PostOrder(struct node *p)
{
    if(p != NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{

    CreateBinaryTree();

    cout << endl;
    cout << "PreOrder Traversal : ";
    PreOrder(root);
    cout << endl;

    cout << endl;
    cout << "InOrder Traversal : ";
    InOrder(root);
    cout << endl;

    cout << endl;
    cout << "PostOrder Traversal : ";
    PostOrder(root);
    cout << endl;

    return 0;
}
