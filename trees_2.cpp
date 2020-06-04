// Creating binary tree (using queue)
// Preorder , Inorder , Postorder Traversals (Iterative Procedure)

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
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

void IPreOrder(struct node *p)
{
    stack<struct node *>s;
    while(p!=NULL || !s.empty())
    {
        if(p!=NULL)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void IInOrder(struct node *p)
{
    stack<struct node *>s;
    while(p!=NULL || !s.empty())
    {
        if(p!=NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void IPostOrder(struct node *p)
{

}

int main()
{

    CreateBinaryTree();

    cout << endl;
    cout << "PreOrder Traversal : ";
    IPreOrder(root);
    cout << endl;

    cout << endl;
    cout << "InOrder Traversal : ";
    IInOrder(root);
    cout << endl;

    cout << endl;
    cout << "PostOrder Traversal : ";
    IPostOrder(root);
    cout << endl;

    return 0;
}

