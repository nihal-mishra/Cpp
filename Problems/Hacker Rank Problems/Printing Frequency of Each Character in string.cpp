#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{   
    map<char,int> mp;
    char s[100];
    gets(s);
    int i=0;
    while(s[i]!='\0')
    {
        mp[s[i]]++;
        i++;
    }
    map<char,int> :: iterator it;
    
    cout<<"\t"<<"Char\t->\tFrequency\n";
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<"\t\'"<<it->first<<"\'\t"<<"->"<<"\t"<<it->second<<"\t"<<endl;
    }
}