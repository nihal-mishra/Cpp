#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;

void reverse(node *cur)
{
    if(cur->next==NULL)
    {
        head=cur;
        return ;
    }
    reverse(cur->next);
    /* line 21 and 22 can also be written as cur->next->next , in that case temp pointer would not be required */
    node* temp=cur->next;
    temp->next=cur;        
    cur->next=NULL;
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
    reverse(head);
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
    
}