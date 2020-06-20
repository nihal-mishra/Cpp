#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node *rootptr = NULL;

node *add(int data)
{
    node *nn = new node;
    nn->data=data;
    nn->left = nn->right = NULL;
    return nn;
}

node *insert(node *node, int data)
{
    if(node==NULL)
        node = add(data);

    else if(node->data>data)
        node->left = insert(node->left,data);
    
    else
        node->right = insert(node->right,data);
    
    return node;
}

void inorder(node *node)
{
    if(node==NULL)
    return;

    inorder(node->left);
    cout<<node->data<<"\t";
    inorder(node->right);
}


bool childrenSum(node *node)
{
    if(node==NULL && node->left==NULL && node->right==NULL)
        return true;
    
    if(node!=NULL && node->left==NULL && node->right==NULL)
        return true;
    
    int sum=0;

    if(node->left != NULL)
        sum = sum + node->left->data;   

    if(node->right != NULL)
        sum = sum + node->right->data; 

    if(node->data == sum && childrenSum(node->left) && childrenSum(node->right))
        return true;
    
    else
        return false;
}

int main()
{
    rootptr=insert(rootptr,10);
    rootptr=insert(rootptr,5);
    rootptr=insert(rootptr,6);
    rootptr=insert(rootptr,1);
    rootptr=insert(rootptr,3);
    rootptr=insert(rootptr,2);
    rootptr=insert(rootptr,4);
    
    cout<<endl;
    cout<<"\nINORDER \t::\t";
    inorder(rootptr);
    cout<<endl;
    cout<<endl;
    if(childrenSum(rootptr))
        cout<<"This tree have Children Sum property\n";
    else
        cout<<"This tree does not have Children Sum property\n";
}