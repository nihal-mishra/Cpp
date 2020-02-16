#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *front = NULL;
node *rear = NULL;

void enQ(int x)
{
    node *nn=new node();
    nn->data=x;
    nn->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=nn;
        rear=nn;
        return;
    }
    rear->next=nn;
    rear=nn;
}
void deQ()
{
    node *temp=front;
    if(rear==NULL && front==NULL)
    {
        cout<<"\n\nQueue is alreay empty cannot DeQueue more.\n";
        return;
    }
    else if(rear==front)
    {
        front = rear = NULL;
        return;
    }
    else
    {
        temp=front;
        front=front->next;
    }
    delete(temp);
    
}

void print()
{
    node * temp=front;
    if(temp==NULL)
    {
        cout<<"\nCannot print an empty Queue\n";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}

bool isEmpty()
{
    return (front==NULL && rear == NULL)?true:false;
}

int Front()
{
    if(front==NULL)
    {
        cout<<"\nCannot show front element of this Queue because there isn't one.\n";
        return -1;
    }
    return front->data;
}

int main()
{
    cout<<"\nisEmpty\t::\t"<<isEmpty();
    cout<<"\nFront\t::\t"<<Front();
    cout<<"\nEnQueue\t::\t10";
    enQ(10);
    cout<<"\nEnQueue\t::\t20";
    enQ(20);
    cout<<"\nEnQueue\t::\t30";
    enQ(30);
    cout<<"\nPrinting\t::\n";
    print();
    cout<<"\n";
    cout<<"\nFront\t::\t"<<Front();
    cout<<"\nDequeue\t::\t";
    deQ();
    cout<<"\nFront\t::\t"<<Front();
    cout<<"\nPrinting\t::\n";
    print();
    cout<<"\n";
    cout<<"\nEnQueue\t::\t40";
    enQ(40);
    cout<<"\nEnQueue\t::\t50";
    enQ(50);
    cout<<"\nisEmpty\t::\t"<<isEmpty();
    cout<<"\nPrinting\t::\n";
    print();
    cout<<"\n\n\n";
}