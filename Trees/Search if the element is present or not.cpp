#include<iostream>
using namespace std;
struct node
{
    int data;
    node* left,*right;
};
node *rootptr=NULL;

node *add(int data)
{
    node *nn=new node;
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}

node *insert(node *n,int data)
{
    if(n==NULL)
    {
        n=add(data);
    }
    else if(n->data > data)
    {
        n->left=insert(n->left,data);
    }
    else
    {
        n->right=insert(n->right,data);
    }
    return n;
}

bool search(node *root,int data)
{
    if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return search(root->left,data);
	}
	else {
		return search(root->right,data);
	}
    
}

void inorder(node* n)
{
    if(n==NULL)
    {
        return;
    }
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
int main()
{
    int n,x;
    cout<<"No. of Nodes :: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Node data :: ";
        cin>>x;
        rootptr=insert(rootptr,x);
    }
    inorder(rootptr);
    cout<<"Enter the element you want to check is present in tree or not :: ";
    cin>>n;
    if(search(rootptr,n))
    {
        cout<<"\nIt is present\n";
    }
    else
    {
        cout<<"\nIt is Not present\n";
    }
    
}