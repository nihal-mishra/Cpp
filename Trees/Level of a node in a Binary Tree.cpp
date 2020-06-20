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
    return NULL;
}

node* insert(node *root, int data)
{
    if(root==NULL)
    root=add(data);

    else if(root->data > data)
    root->left=insert(root->left,data);

    else
    root->right=insert(root->right,data);

    return root;
}

void inorder(node *root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int getLevelUtil(node* node,int data, int level)
{
    if (node == NULL) 
        return 0; 
  
    if (node -> data == data) 
        return level; 
  
    int downlevel = getLevelUtil(node -> left, data, level + 1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(node->right, data, level + 1); 
    return downlevel; 
}
int getLevel(node *node, int data) 
{ 
    return getLevelUtil(node, data, 1); 
} 
int main()
{
    rootptr=insert(rootptr,1104);
    rootptr=insert(rootptr,102);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,100);
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,1304);
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
    cout<<endl;
    inorder(rootptr);
    int level=getLevel(rootptr,100);
    cout<<"Level of the node is  :: "<<level<<endl;
}