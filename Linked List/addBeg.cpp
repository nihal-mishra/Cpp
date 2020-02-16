#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;

};

node* head;

void insert(int data)
{
    node* temp=new node();
    temp->data=data;
    temp->next=head;
    head=temp;
}

void print()
{
    node* temp=new node();
    temp=head;
    while(temp!=NULL)
    {   
        printf("\n");
        cout<<"DATA =  "<<temp->data;
        printf("\n");
        cout<<"LINK =  "<<temp->next;
        printf("\n\n");
        temp=temp->next;
    }
}

int main()
{
    head=NULL;
    int n;
    printf("How many node you want :: ");
    cin>>n;
    int d;
    printf("\n\n");
    for(int i=0;i<n;i++)
    {
      printf("\n");
      printf("Enter data :: ");
      cin>>d;
      insert(d);
    }
    cout<<"LINKED LIST :: ";
    printf("\n");
    print();
}