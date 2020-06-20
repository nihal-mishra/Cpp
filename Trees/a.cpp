#include<iostream>
#include<map>
#include<utility> 
using namespace std; 

// Structure of binary tree 
struct Node{ 
	Node * left; 
	Node* right; 
	int data; 
}; 

// function to create a new node 
Node* newNode(int key){ 
	Node* node=new Node(); 
	node->left = node->right = NULL; 
	node->data=key; 
	return node; 
} 

void fill(Node *root,int HD,int level, map<int,pair<int,int> > &hd_data_level)
{
	if(root==NULL)
	{return;}

	if(hd_data_level.count(HD)==0  || hd_data_level[HD].second>level)
	{
		hd_data_level[HD]=make_pair(root->data,level);
	}

	fill(root->left,HD-1,level+1,hd_data_level);
	fill(root->right,HD+1,level+1,hd_data_level);

}

// function should print the topView of 
// the binary tree 
void topView(Node *root){ 

	map<int,pair<int,int> > hd_data_level;
	fill(root,0,0,hd_data_level);
	cout<<"\n";
	cout<<"HD.\tData\tLevel\n";
	for(auto i=hd_data_level.begin();i!=hd_data_level.end();i++)
	{
		cout<<i->first<<"\t"<<i->second.first<<"\t"<<i->second.second<<endl;
	}
	cout<<"\n\nTOP VIEW :: ";
	for(auto i=hd_data_level.begin();i!=hd_data_level.end();i++)
	{
		cout<<i->second.first<<" ";
	}
	cout<<"\n\n";
} 
// Driver Program to test above functions 
int main(){ 
	Node* root = newNode(10); 
	root->left = newNode(8); 
	root->right = newNode(30); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->left->right->right = newNode(6); 
	topView(root); 
	return 0; 
} 
/* This code is contributed by Akash Debnath */
