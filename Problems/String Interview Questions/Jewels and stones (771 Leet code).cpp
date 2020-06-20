#include<iostream>
#include<map>
using namespace std;
/*
Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
*/
int numJewelsInStones(string J, string S)
{
    int ans=0;
    map<char,int> m;
    for(auto ch:J)
        m[ch];

    for(auto ch:S)
        if(m.find(ch)!=m.end())
            ans++;

    return ans;
}

int main()
{
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;
    int ans= numJewelsInStones(str1,str2);
    cout<<"\n"<<ans<<endl;
}