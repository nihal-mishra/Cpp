#include<iostream>
using namespace std;

bool check(string s, int st, int end)
{
    if(st==end) return true;

    if(st>end) return true;

    if(s[st] != s[end])
    return false;

    return check(s,st+1,end-1);
}

int main()
{
    string s = "NIHALLAHI";
    if(check(s,0,s.length()-1))
    {
        cout<<"\nIt is plaindromic string"<<endl;
    }
    else
    {
        cout<<"\nIt is not a plaindromic string"<<endl;
    }
    
}