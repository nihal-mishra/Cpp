#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;

void del()
{
    node *cur=head;
    node *n = NULL;

    while(cur!=NULL)
    {
        n=cur->next;
        delete cur;
        cur=n;
    }
    head=NULL;

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
    del();
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
    
}