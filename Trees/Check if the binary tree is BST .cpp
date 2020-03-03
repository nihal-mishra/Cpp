#include<iostream>
#include<climits>
int int_max=INT_MAX;
int int_min=INT_MIN;
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

node *insert(node *root, int data)
{
    if(root==NULL)
    {
        root=add(data);
    }
    else if(root->data > data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
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
    cout<<root->data<<"  ";
    inorder(root->right);
}

bool checkBST(node *root,int min,int max)
{
    if(root==NULL)
    return true;

    if(root->data>min && root->data<max && checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max))
        return true;
    else return false;
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
    inorder(rootptr);
    cout<<endl;
    cout<<endl;
    if(checkBST(rootptr,int_min,int_max))
    {
        cout<<"\n\nIT IS A BINARY SEARCH TREE\n\n";
    }
    else
    {
        cout<<"\n\nIT IS NOT A BINARY SEARCH TREE\n\n";
    }
}