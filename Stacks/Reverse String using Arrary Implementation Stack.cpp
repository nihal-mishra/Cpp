#include<iostream>
using namespace std;
#define max 101
char stack[max];
int top=-1;

void reverse(char *ch /* Or we can write char ch[] both are same*/ ,int len)
{
    for(int i=0;i<len;i++)
    {
        stack[i]=ch[i];
        ++top;
    }
    for(int i=0;i<len;i++)
    {
        ch[i]=stack[top];
        --top;
    }
}

int main()
{
    cout<<"\tEnter a String ::\t";
    char chr[51];
    gets(chr); // Using gets() here because cin>> will not take string beyond a space if there is a space present.
    reverse(chr, strlen(chr));
    cout<<"\tReversed String :: \t"<<chr<<"\n\n";
}