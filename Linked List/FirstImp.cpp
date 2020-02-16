#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
    struct node
    {
        int data;
        node* link;
    };

    node* A;
    A=NULL;

    node* temp= new node();
    cout<<"ENTER DATA IN NODE : "<<endl;
    cin>>temp->data;
    cout<<"\n\n";
    temp->link=NULL;

    A=temp;
    cout<<"NODE 1 data :: "<<temp->data;
    cout<<"\n\n";
    cout<<"NODE 1 link :: "<<temp->link;
    cout<<"\n\n";

    temp = new node();
    cout<<"ENTER DATA IN NODE : "<<endl;
    cin>>temp->data;
    cout<<"\n\n";
    temp->link=NULL;
    
    node* temp1 = A;
    while(temp1->link!=NULL)
    {
        temp1=temp1->link;
    }
    temp1->link=temp;
    
    cout<<"NODE 1 data :: "<<temp1->data;
    cout<<"\n\n";
    cout<<"NODE 1 link :: "<<temp1->link;
    cout<<"\n\n";
}