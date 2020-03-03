#include<iostream>
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
        node->right=insert(node->right,data);
    }
    else
    {
        node->left=insert(node->left,data);
    }
    return node;
}

void inorder(node *node)
{
    if(node==NULL)
    {
        return;
    }
    inorder(node->left);
    cout<<node->data<<"\t";
    inorder(node->right);
}

int height(node *node)
{
    if(node == NULL)
    {
        return -1;
    }
    int Lefth = height(node->left);
    int righth = height(node->right);
    return max(Lefth,righth)+1;
    /*
    ALSO CAN BE USED DIRECTLY ::
    return max(height(node->left),height(node->right))+1;
    */
}

int main()
{
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,102);
    cout<<"\n";
    cout<<"INORDER ::\t";
    inorder(rootptr);
    cout<<"\n";
    cout<<"\n";
    cout<<"HEIGHT OF THE TREE :: "<<height(rootptr)<<endl;
}