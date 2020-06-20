#include<iostream>
#include<map>
#include<utility>
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
    {
        root=add(data);
    }
    else if(root->data > data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
void fillmap(node *root,int HD,int Level,  map<int,pair<int,int> > &HD_data_level)
{
    if(root==NULL)
    return;

    if(HD_data_level.count(HD)==0)
    {
        HD_data_level[HD] = make_pair(root->data,Level);
    }
   else if(HD_data_level[HD].second > Level)
    {
        HD_data_level[HD]=make_pair(root->data,Level);
    }

    fillmap(root->left,HD-1,Level+1,HD_data_level);
    fillmap(root->right,HD+1,Level+1,HD_data_level);
}

void topview(node *root)
{
    map<int,pair<int,int> > HD_data_level;
    fillmap(root,0,0,HD_data_level);
     map<int,pair<int,int> > :: iterator it;
     cout<<"\nTOP VIEW :: ";
     for(it=HD_data_level.begin();it!=HD_data_level.end();it++)
     {
         cout<<it->second.first<< " ";
     }
    cout<<"\n\n";
     cout<<"HD\tData\tLevel\n";
     for(it=HD_data_level.begin();it!=HD_data_level.end();it++)
     {
         cout<<it->first<<"\t"<<it->second.first<<"\t"<<it->second.second<<endl;
     }
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
    rootptr=insert(rootptr,190);
    rootptr=insert(rootptr,80);
    rootptr=insert(rootptr,14);
    rootptr=insert(rootptr,104);
    rootptr=insert(rootptr,102);
    topview(rootptr);
}