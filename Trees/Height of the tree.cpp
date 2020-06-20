#include<iostream>
#include<unordered_map>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    int h;
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
    else if(node->data<data)
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

int height(node *node, unordered_map<int,int> &Data_height)
{
    if(node == NULL)
    {
        return -1;
    }
    int Lefth = height(node->left,Data_height);
    int righth = height(node->right,Data_height);

    node->h = max(Lefth,righth)+1;
    Data_height[node->data]=node->h;
    return node->h;
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
    unordered_map<int,int> Data_height;
    cout<<"\n";
    cout<<"\n";
    cout<<"HEIGHT OF THE TREE :: "<<height(rootptr,Data_height)<<endl;
    unordered_map<int,int>::iterator it;
    cout<<"\n\n";
    for(it=Data_height.begin();it!=Data_height.end();it++)
    {   
        cout<<it->first<<"\t->\t"<<it->second<<endl;
    }
}