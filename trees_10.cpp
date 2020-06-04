// Generating BST from Preorder

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *root = NULL;

void CreatePre(int Pre[] , int n)
{
    stack<struct node *>stk;
    struct node *t , *p;
    int i=0;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = Pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i<n)
    {
        if(Pre[i] < p->data)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = Pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p=t;
        }
        else
        {
            if(!stk.empty())
            {
                if(Pre[i] > p->data && Pre[i] < stk.top()->data)
                {
                    t = (struct node *)malloc(sizeof(struct node));
                    t->data = Pre[i++];
                    t->lchild = t->rchild = NULL;
                    p->rchild = t;
                    p=t;
                }
                else
                {
                    p = stk.top();
                    stk.pop();
                }
            }
            else
            {
                if(Pre[i] > p->data)
                {
                    t = (struct node *)malloc(sizeof(struct node));
                    t->data = Pre[i++];
                    t->lchild = t->rchild = NULL;
                    p->rchild = t;
                    p=t;
                }
            }
        }
    }
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
    int Pre[] = {30,20,10,15,25,40,50,45};
    int n = sizeof(Pre)/sizeof(Pre[0]);

    CreatePre(Pre,n);
    Inorder(root);

    return 0;
}
