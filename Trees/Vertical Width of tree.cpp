#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node * rootptr=NULL;;

node *add(int data)
{
    node *nn=new node;
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}

node *insert(node *root,int data)
{
    if(root==NULL)
    {
        root=add(data);
    }
    else if(root->data>data)
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
    cout<<root->data<<" ";
    inorder(root->right);
}

void width(node* root, int &min, int &max, int cur)
{
    if(root==NULL)
    {
        return;
    }

    width(root->left, min, max, cur-1);

    if(min>cur)
    min=cur;

    if(max<cur)
    max=cur;

    width(root->right, min, max, cur+1);
}


int main()
{
    node *rootptr=NULL;
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,204);
    rootptr=insert(rootptr,404);
    rootptr=insert(rootptr,1104);
    
    cout<<"INORDER :: ";
    inorder(rootptr);
    cout<<"\n";
    int min,max=0;
    width(rootptr,min,max,0);
    int sum=abs(min)+max;
    cout<<"\n\nwidth :: "<<sum<<endl;
}