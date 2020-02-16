#include<iostream>
#include<string>
using namespace std;
/*
Orignal String  ::      Nihal Mishra 
Reversed String ::      lahiN arhsiM
*/
void rev(char *st,int len)
{
    for(int i=0;i<len/2;i++)
    {
        char temp=st[i];
        st[i]=st[len-i-1];
        st[len-i-1]=temp;
    }
}

int main()
{
    char str[100];
    char re[100]="",word[50];
    cout<<"\nEnter a string\t::\t";
    gets(str);
    int count=0;
    strcat(str," ");
    cout<<"\nOrignal String\t::\t"<<str;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            word[count]='\0';
            rev(word,count);
            strcat(re,word);
            strcat(re," ");
            count=0;
        }
        else
        {
            word[count]=str[i];
            count++;
        }
        
    }
    cout<<"\n\nReversed String\t::\t"<<re;
    cout<<"\n\n";
}