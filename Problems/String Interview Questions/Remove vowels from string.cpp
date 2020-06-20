#include<iostream>
#include<string>
using namespace std;

int main()
{
    char str[10];
    cin>>str;
    char s2[10];
    int d=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]!='a' and str[i]!='e' and str[i]!='i' and str[i]!='o' and str[i]!='u' and str[i]!='A' and str[i]!='E' and str[i]!='I' and str[i]!='O' and str[i]!='U')
        {
            s2[d]=str[i];
            cout<<s2[d]<<endl;
            d++;
        }    
    }
    cout<<"\n";
    cout<<s2;
    cout<<"\n";
    for(int i=0;i<d;i++)
    {
        cout<<s2[i];
    }
    cout<<"\n";
}