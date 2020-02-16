#include<stdio.h>
#include<iostream>
using namespace std;

struct node1
{
    int data;
    node1* next;
};
node1* head1;
node1* head2;

bool compare()
{
    node1 *L1=head1;
    node1 *L2=head2;

    while(L1 !=NULL && L2!=NULL)
    {
        if(L1->data != L2->data)
        {

            return false;
        }
        L1=L1->next;
        L2=L2->next;
    }
    return (L1 == NULL && L2 == NULL);;
}

void insert(int d1 , int d2)
{
   node1* NewN1=new node1();
   NewN1->data=d1;
   NewN1->next=NULL;

   node1* NewN2=new node1();
   NewN2->data=d2;
   NewN2->next=NULL;

   if(head1==NULL)
   {
       head1=NewN1;
   }
   else
   {
       node1* last1=head1;
       while(last1->next!=NULL)
       {
           last1=last1->next;
       }
       last1->next=NewN1;
   }

    if(head2==NULL)
   {
       head2=NewN2;
   }
   else
   {
       node1* last2=head2;
       while(last2->next!=NULL)
       {
           last2=last2->next;
       }
       last2->next=NewN2;
   }
}

void print()
{
    node1* temp1=new node1();
    temp1=head1;
    cout<<"LINKED LIST 1 \n";
    while(temp1!=NULL)
    {
        cout<<" "<<temp1->data;
        temp1=temp1->next;
        
    }


    node1* temp2=new node1();
    temp2=head2;

    cout<<"\n\n\nLINKED LIST 2 \n";
    while(temp2!=NULL)
    {
        cout<<" "<<temp2->data;
        temp2=temp2->next;
        
    }
}

int main()
{
    head1=NULL;
    head2=NULL;
    bool TF;
    insert(1,1);
    insert(2,2);
    insert(3,3);
    insert(4,4);
    insert(5,5);
    TF=compare();
    printf("\n\n\n");
    print();
    printf("\n\n\n");
    if(TF==true)
    {
    cout<<"Both LINKED LISTS are identical\n";
    }
    else
    {
    cout<<"Both LINKED LISTS NOT identical\n";
    }
    
}