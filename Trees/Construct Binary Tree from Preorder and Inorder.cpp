#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node *root==NULL;

node *newNode(int data)
{
    node *nn=new node;
    node->data=data;
    node->left=node->right=NULL;
    return nn;
}
buildTree(vector<int> pre, vector<int> in, int PreStart, int PreEnd, int InStart, int InEnd)
{
    
}
int main() 
{ 
    vector<int> pre;
    vector<int> in;

    buildTree(pre, in, 0, pre.size()-1, 0, in.size())

}