#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;

void insert(int d)
{
   node* NewN=new node();
   NewN->data=d;
   NewN->next=NULL;

   if(head==NULL)
   {
       head=NewN;
   }
   else
   {
       node* last=head;
       while(last->next!=NULL)
       {
           last=last->next;
       }
       last->next=NewN;
   }
}

void insertn(int n,int data)
{
   node* NewN=new node();
   NewN->data=data;
   NewN->next=NULL;


    if (n == 0) {
       NewN->next = head;
       cout<<"INVALID POSITION..";
       return;
    }
   if(n==1)
   {
       NewN->next = head;
       head=NewN;
       return;
   }

   node *temp=head;
   for(int i=1;i<n-1 && temp->next!=NULL ;i++) // THIS STATEMENT IS WHEN "AT POSITION" YOU WANT TO ENTER
   //for(int i=1;i<n && temp->next!=NULL ;i++) // THIS STATEMENT IS WHEN "AFTER THE POSITION" YOU WANT TO ENTER
   {
       temp=temp->next;
   }
   NewN->next=temp->next;
   temp->next=NewN;

   
}

void print()
{
    node* temp=new node();
    temp=head;
    while(temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    cout<<" \n";
}

int main()
{
   /* head=NULL;
    int n,data;
    cout<<"Enter 1st node data :: ";
    cin>>data;
    insert(1,data);
    print();
    cout<<"\n\n"<<"Enter new node's position : ";
    cin>>n;
    cout<<"\n"<<"Enter new node's data : ";
    cin>>data;
    insert(n,data);
    print();
    cout<<"\n\n"<<"Enter new node's position : ";
    cin>>n;
    cout<<"\n"<<"Enter new node's data : ";
    cin>>data;
    insert(n,data);
    print();
    */

   head=NULL;
   int n,data;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
     cout<<"\n\n"<<"Enter new node's position : ";
    cin>>n;
    cout<<"\n"<<"Enter new node's data : ";
    cin>>data;
    insertn(n,data);
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
}