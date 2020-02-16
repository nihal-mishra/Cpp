#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;

stack<node *> stk;

void insert(int data)
{
    node *NewN=new node();
    NewN->data=data;
    NewN->next=NULL;
    if(head==NULL)
    {
        head=NewN;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NewN;
}

void print()
{
    node *temp=head;
    if(temp==NULL)
    {
        cout<<"\nNOTHING TO PRINT.\n";
        return;
    }
    while(temp!=NULL)
    {
        cout<<"\t"<<temp->data;
        temp=temp->next;
        
    }
    cout<<"\n";
}

void rev()
{ 
    //PUSH
    node *temp=head;
    while(temp!=NULL)
    {
        stk.push(temp);
        cout<<"\nSTACK SIZE push :: "<<stk.size()<<endl;
        temp=temp->next;
    }
    head=stk.top();
    temp=head;
    stk.pop();
    while(!stk.empty())
    {
        temp->next=stk.top();
        cout<<"\nTOP :: "<<stk.top();
        temp=temp->next;
        stk.pop();
        
    }
    temp->next=NULL;
}

 int main()
 {
     int len=0,x=0;
     cout<<"Enter Length of Linked List :: ";
     cin>>len;
     for(int i=0;i<len;i++)
     {
         cout<<"\nENTER :: ";
         cin>>x;
         insert(x);
         print();
     }

     cout<<"\nLINKED LIST :: ";
     print();
     rev();
     cout<<"\n\n Reversed LINKED LIST :: ";
     print();
 }