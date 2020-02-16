#include<iostream>
#include<string>
using namespace std;
/*
Orignal String  ::      Nihal Mishra 
Reversed String ::      Mishra Nihal
*/

void rev(char word[],int len)
{
    char temp;
    for(int i=0;i<len/2;i++)
    {
        temp=word[i];
        word[i]=word[len-i-1];
        word[len-i-1]=temp;
    }
}

int main()
{
    char str[1000],word[500],re[1000]="";
    int count=0;
    cout<<"\nEnter a String\t::\t";
    gets(str);
    cout<<"\n\nOrignal String\t::\t"<<str;
    rev(str,strlen(str));
    strcat(str," ");
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
    cout<<"\nReversed String\t::\t"<<re<<"\n\n";
}
