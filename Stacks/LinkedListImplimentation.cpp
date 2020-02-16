#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *top=NULL;;

void push(int d)
{
    node *NN = new node();
    NN->data =d;
    NN->next =top;
    top=NN;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"\nERROR :: Underflow :: Cannot pop from empty stack"<<endl;
        return; 
    }

    node *temp=top;
    top=top->next;
    delete(temp);
}

void print()
{
    if(top==NULL)
    {
        cout<<"\nSTACK :: Empty Stack Pr";
        cout<<"\n";
        return;
    }
    node *temp=top;
    cout<<"\n\nSTACK :: ";
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->data;
        temp=temp->next;
    }
}

void peek()
{
    if(top==NULL)
    {
        cout<<"\nSTACK :: Empty Stack";
        cout<<"\n";
    }
    else
    cout<<"TOP :: "<<top->data;
}

void isempty()
{
    if(top==NULL)
    {
        cout<<"\nSTACK :: Empty Stack";
    }
    else
    {
        cout<<"\nSTACK :: Not Empty";
    }
    
}

int main()
{
    print();
    isempty();
    push(10);
    print();
    push(20);
    print();
    pop();
    print();
    push(30);
    print();
    push(110);
    print();
    push(120);
    print();
}