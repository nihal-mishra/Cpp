#include<iostream>
#include<unordered_map>
using namespace std;

char check(string s)
{
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }

    for(int i=0;i<s.length();i++)
    {
        if(mp[s[i]]==1)
        {
            return s[i];
        }
    }

    return '_';
}
int main()
{
    string s = "aaabbbcbbbaaabbcff";
    char f=check(s);

    if(f == '_')
    {
        cout<<"\nEvery char is repeating.\n";
    }
    else
    {
        cout<<"\n"<<f<<" is the first non repeating char.\n";
    }
    
}