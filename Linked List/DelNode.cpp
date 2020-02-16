#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;

void del(int pos)
{
    node *curr=head;
    node *trail=NULL;
    
    if(pos==1)
    {
        head=curr->next;
        delete curr;
        return;
    }

    if(pos==0 || pos<0)
    {
        cout<<"INVALID INPUT \n";
        return;
    }
    
    for(int i=1; i<pos;i++)
    {
        trail=curr;
        curr=curr->next;
    }
    trail->next=curr->next;
    delete curr;
    return;
}

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

void print()
{
    node* temp=new node();
    temp=head;
    while(temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
        
    }
    printf("\n");
}

int main()
{
    head=NULL;
    int n,data;
    printf("How much node you want to add ::  ");
    cin>>n;
    printf("\n");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("\n");
        printf("Enter data :: ");
        cin>>data;
        insert(data);
        printf("\n");
        printf("\n");
        print();

    }
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");

    int pos;
    printf("Delete node from position (List Starting from 1) :: ");
    cin>>pos;
    del(pos);
    print();

    
}