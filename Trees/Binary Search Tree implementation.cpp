#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node *rootptr;

node *add(int data)
{
    node *nn=new node();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

node* insert(node *root,int data)
{
    if(root==NULL)
    {
        root=add(data);
    }
    else if(root->data <= data)
    {
        root->left=insert(root->left,data);
    }
    else 
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<"root->data :: "<<root->data<<"\n";
    inorder(root->right);
}

int main()
{
    int n,x;
    cout<<"No. of Nodes :: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Node data :: ";
        cin>>x;
        rootptr=insert(rootptr,x);
    }
    inorder(rootptr);
}