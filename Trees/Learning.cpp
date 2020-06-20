#include<iostream>
#include<unordered_map>
#include<iterator>
using namespace std;

char firstNonRepeating(string s)
{
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
       if(mp[s[i]] == 1)
        return s[i];
    }
    return '_';
}

int main()
{
    string s = "aaacccdeeef";
    char c = firstNonRepeating(s);
    cout<<"\n"<<c<<endl;
}