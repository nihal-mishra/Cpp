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
    root=add(data);

    else if(root->data > data)
    root->left = insert(root->left,data);

    else 
    root->right = insert(root->right,data);

    return root;
}

void inorder(node* root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void width(node *root, int &min, int &max, int horizontalDis)
{
    if(root==NULL)
    return;

    width(root->left,min,max,horizontalDis-1);
    
    if(min>horizontalDis)
    min=horizontalDis;

    if(max<horizontalDis)
    max=horizontalDis;

    width(root->right,min,max,horizontalDis+1);
}

void VerticalOrderTraversal(node *root, int verticalLine, int horizontalData)
{
    if(root==NULL)
    return;

    if(verticalLine==horizontalData)
    cout<<root->data<<" ";

    VerticalOrderTraversal(root->left,verticalLine,horizontalData-1);
    VerticalOrderTraversal(root->right,verticalLine,horizontalData+1);
}

int main()
{
    node *rootptr=NULL;
    rootptr=insert(rootptr,1104);
    rootptr=insert(rootptr,102);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,1304);
    
    cout<<"INORDER :: ";
    inorder(rootptr);
    cout<<"\n";
    int min=0,max=0;
    width(rootptr,min,max,0);
    int width = abs(min)+max;
    cout<<"\nWidth :: "<<width<<endl<<endl;
    cout<<"VERTICAL ORDER :: ";
    for(int j=min;j<=max;j++)
    {
        VerticalOrderTraversal(rootptr,j,0);
    }
    cout<<"\n\n";
}