#include <iostream>
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

int rangeSum(node *root, int low, int high)
{
    if(root==NULL)
    return 0;

    if(root->data>=low && root->data<=high)
    return root->data+rangeSum(root->left, low, high) + rangeSum(root->right, low, high);

    else if(root->data<low)
    return rangeSum(root->right, low, high);

    else 
    return rangeSum(root->left, low, high);
}

int main()
{
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,102);
    cout<<"\n"<<rangeSum(rootptr,14,102)<<endl;
}