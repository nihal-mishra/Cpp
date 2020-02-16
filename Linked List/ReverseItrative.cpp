#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;

void reverse()
{
    node *cur=head;
    node *pre= NULL;
    node *next=NULL;
    while (cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    
    head=pre;

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
}

int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
    reverse();
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
    
}