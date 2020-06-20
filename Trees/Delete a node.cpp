#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
node *root = NULL;

node *add(int data)
{
    node *nn=new node;
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

node *insert(node *root, int data)
{
    if(root == NULL)
    {
        root = add(data);
    }
    else if(root->data>data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return nn;
}

node *findMin(node *root)
{
    while(root->left != NULL)
        root = root->left;
    
    return root;
}

node* del(node *root, int data)
{
    if(root==NULL)
        return NULL;

    else if(root->data > data)
        root->left = del(root->left, data);
    
    else if(root->data < data)
        root->right = del(root->right, data);
    
    else
    {
        // NO child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
             
        }
        
        // Single Child
        else if(root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
            
        }
        else if(root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
            return temp;
        }

        // Two children
        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
        
    }
    
}

int main()
{

}