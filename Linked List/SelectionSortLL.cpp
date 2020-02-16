#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* head;

void selectionsort()
{
    node *i=head;
    node *j;
    int temp;
    for(i=head;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data > j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

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
    insert(100);
    insert(22);
    insert(3334);
    insert(422);
    insert(1345);
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
    selectionsort();
    printf("\n\n\nLINKED LIST ::: ");
    print();
    printf("\n\n\n");
    
}