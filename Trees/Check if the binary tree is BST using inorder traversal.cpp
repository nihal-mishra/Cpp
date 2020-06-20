#include <iostream>
#include <vector>
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
    else if(node->data>data)
    {
        node->left=insert(node->left,data);
    }
    else
    {
        node->right=insert(node->right,data);
    }
    return node;
}

void inorder (node *node)
{
    if(node==NULL)
    {
        return;
    }
    inorder(node->left);
    cout<<node->data<<"\t";
    inorder(node->right);
}

void Store_inorder(node *root, vector<int> &v)
{
    if(root==NULL)
    return;

    Store_inorder(root->left,v);
    v.push_back(root->data);
    Store_inorder(root->right,v);
}

bool checkBST(node *node)
{
    vector<int> v;
    Store_inorder(node,v);

    for(int i=1;i<v.size()-1;i++)
    {
        if(v[i]<v[i-1])
        {
            return false;
        }
    }
    return true;
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
    if(checkBST(rootptr)) cout<<"It is a Binary Search Tree\n";
    else cout<<"It is NOT a Binary Search Tree\n";
}