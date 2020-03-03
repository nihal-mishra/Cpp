#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node *rootptr=NULL;

node *add(int data)
{
    node *nn=new node;
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}

node *insert(node *node , int data)
{
    if(node==NULL)
    {
        node=add(data);
    }
    else if(node->data > data)
    {
        node->left=insert(node->left,data);
    }
    else
    {
        node->right=insert(node->right,data);
    }
    return node;
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}

void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *current=q.front();
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
        cout<<current->data<<"\t";
        q.pop();
    }
}

int main()
{
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,103);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,1032);
    rootptr=insert(rootptr,1048);
    rootptr=insert(rootptr,1044);
    rootptr=insert(rootptr,89);
    rootptr=insert(rootptr,30);
    rootptr=insert(rootptr,85);
    cout<<endl;
    cout<<"\nINORDER \t::\t";
    inorder(rootptr);
    cout<<endl;
    cout<<endl;
    cout<<"\nPREORDER\t::\t";
    preorder(rootptr);
    cout<<endl;
    cout<<endl;
    cout<<"\nPOSTORDER\t::\t";
    postorder(rootptr);
    cout<<endl;
    cout<<endl;
    cout<<"\nLEVELORDER\t::\t";
    levelorder(rootptr);
    cout<<endl;
    cout<<endl;
}