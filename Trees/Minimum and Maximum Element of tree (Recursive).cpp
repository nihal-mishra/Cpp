#include<iostream>
#include<climits>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node *add(int data)
{
    node *nn=new node;
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
node *insert(node *node,int data)
{
    if(node==NULL)
    {
        node=add(data);
    }
    else if(node->data<data)
    {
        node->right=insert(node->right,data);
    }
    else
    {
        node->left=insert(node->left,data);
    }
    return node;
}
int findmin(node *node)
{
    if(node==NULL)
    {
        cout<<"\nTREE IS EMPTY\n";
        return  INT_MIN;
    }
    else if(node->left==NULL)
    {
        return node->data;
    }
    else
    {
        return findmin(node->left);
    }
    
}

int findmax(node *node)
{
    if(node==NULL)
    {
        cout<<"\n\nTREE IS EMPTY";
        return INT_MAX;
    }
    else if(node->right==NULL)
    {
        return node->data;
    }
    else
    {
        return findmax(node->right);
    }
    
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    //L NODE R
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    cout<<"INORDER :: ";
    inorder(rootptr);
    cout<<"\n";
    cout<<"Max : "<<findmax(rootptr);
    cout<<"\n";
    cout<<"Min : "<<findmin(rootptr);
    cout<<"\n";
}