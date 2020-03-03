#include<iostream>
#include<climits>
using namespace std;
int MIN=INT_MIN;

struct node
{
    int data;
    node *left,*right;
};

node *add(int data)
{
    node *n=new node;
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

node *insert(node *node,int data)
{
    if(node==NULL)
    {
        node=add(data);
    }
    else if(node->data < data)
    {
        node->left=insert(node->left,data);
    }
    else
    {
        node->right=insert(node->right,data);
    }
    return node;
}

int findMin(node *root)
{
    if(root==NULL)
    {
        cout<<"\n\nTree is empty\n";
        return MIN;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

int findMax(node *root)
{
    if(root==NULL)
    {
        cout<<"\n\nTree is empty\n";
        return MIN;
    }
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
void inorder(node *node)
{
    if(node==NULL)
    {
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main()
{
    node *rootptr=NULL;
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,102);
    inorder(rootptr);
    cout<<"\n";
    cout<<findMax(rootptr);
    cout<<"\n";
    cout<<findMin(rootptr);
    cout<<"\n";
}