#include<stdio.h>
#include<iostream>
using namespace std;

#define maxsize 101

int arr[maxsize];
int top=-1;

void push(int data)
{
    if(top==maxsize-1)
    {
        cout<<"\n\nERROR :::: Stack Overflow :::: \n\n";
        return;
    }

    ++top;
    arr[top]=data;
}

void pop()
{
    if(top==-1)
    {
        cout<<"\n\nERROR :::: No elements to remove :::: \n\n";
        return;
    }
    --top;
}

void isempty()
{
    if(top==-1)
    {
        cout<<"\n\n Stack is empty \n\n";
    }
    else
    {
        cout<<"\n\n Stack is not empty \n\n";
    }
}

void print()
{
    if(top==-1)
    {
        cout<<"\n\n Stack is empty, NOTHING to print \n\n";
        return;
    }
    int p=top;
    while(p!=-1)
    {
        cout<<arr[p]<<" ";
        p--;
    }
}

int main()
{
    print();
    push(10);
    print();
    printf("\n");
    push(12);
    print();
    printf("\n");
    push(11);
    print();
    printf("\n");
    isempty();
    pop();
    print();
    printf("\n");
    pop();
    print();
    printf("\n");
    push(111);
    print();
    printf("\n");
    push(123);
    print();
    printf("\n");
    pop();
    print();
    printf("\n");
    pop();
    print();printf("\n");
    pop();
    print();printf("\n");
    pop();
    print();printf("\n");
    isempty();
}