#include<stdio.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head;

void merge(Node *H1 ,Node *H2)
{
    Node *L1=H1;
    Node *L2=H2;
    Node *dummy = new Node();
    head=dummy;

    while(L1!=NULL && L2!=NULL)
    {
        if(L1->data < L2->data)
        {
            dummy->next=L1;
            L1=L1->next;
        }
        else
        {
            dummy->next=L2;
            L2=L2->next;
        }
        dummy=dummy->next;
    }
    if(L1!=NULL)
    {
        dummy->next=L1;
    }
    else
    {
        dummy->next=L2;
    }
}

void print(Node *ptr)
{
    Node* temp=new Node();
    temp=ptr;
    while(temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
        
    }
}

struct Node *newNode(int x) 
{ 
    Node *temp = new Node; 
    temp->data = x; 
    temp->next = NULL; 
    return temp; 
} 
  
/* Driver program to test count function*/
int main() 
{ 
    /* Start with the empty list */
 struct Node *head1 = newNode(1); 
    head1->next = newNode(2); 
    head1->next->next = newNode(3); 
    head1->next->next->next = newNode(4); 
    head1->next->next->next->next = newNode(5); 
    head1->next->next->next->next->next = newNode(6); 
    head1->next->next->next->next->next->next =  newNode(7); 
    head1->next->next->next->next->next->next->next =  newNode(8); 
    cout<<"LINKED LIST 1 :: \n";
    print(head1);
    cout<<"\n";
    struct Node *head2 = newNode(1); 
    head2->next = newNode(4); 
    head2->next->next = newNode(13); 
    head2->next->next->next = newNode(33); 
    head2->next->next->next->next = newNode(45); 
    head2->next->next->next->next->next = newNode(91); 
    head2->next->next->next->next->next->next =  newNode(107); 
   // head2->next->next->next->next->next->next->next =  newNode(8); 
    cout<<"\n\nLINKED LIST 2 :: \n";
    print(head2);
    cout<<"\n";
    cout<<"\n";
    merge(head1,head2);
    cout<<"\n\nLINKED LIST MERGED :: \n"; 
    print(head->next);
    cout<<"\n";
    cout<<"\n";
}