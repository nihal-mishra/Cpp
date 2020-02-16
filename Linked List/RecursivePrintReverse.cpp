#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;

void insert(int data)
{
    node *NN=new node();
    NN->data = data;
    NN->next = NULL;

    if(head==NULL)
    {
        head=NN;
        return;
    }
    node *last = head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=NN;
    return;
}

void recurReverse(node *ptr)
{
    if(ptr==NULL)
    {return;}

    recurReverse(ptr->next);
    cout<<ptr->data<<" ";
}

int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    recurReverse(head);
    printf("\n");
}