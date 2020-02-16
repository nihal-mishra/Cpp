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
    
}