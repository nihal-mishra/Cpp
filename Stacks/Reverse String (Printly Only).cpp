#include<iostream>
#include<string>
using namespace std;
#define max 101
char stack[max];
int top = -1;

void reverse(string st,int n)
{
  
   for(int i=0;i<n;i++) //PUSH
   {
     stack[i]=st[i];
     ++top;
   }

   for(int i=0;i<n;i++) //REVERSE
   {
       st[i]=stack[top];
       --top;
   }
   cout<<"\n";
   for(int i=0;i<n;i++) //PRINT
   {
       cout<<st[i]<<"";
   }
   cout<<"\n";
   cout<<"\n";

}

int main()
{
    string str;
    cout<<"\nENTER STRING :: ";
    cin>>str;
    int len=str.length();
    reverse(str,len);
}
