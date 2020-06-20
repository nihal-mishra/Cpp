#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int res=0;
    for(auto ch:s)
    {
        res=res*26;
        res=res+ ch -'A' +1;
    }

    cout<<"\nNum ::"<<res<<endl;
}