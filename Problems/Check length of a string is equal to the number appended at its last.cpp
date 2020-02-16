//#include<bits/stdc++.h>
#include<string>
#include<iostream>

using namespace std;

bool isEqual(string str)
{
    int n=str.length();
    int num,i;
    int x=1;
    //cout<<n;
    for(i=n-1;i>=0;i--)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            num=(str[i] - '0')*x + num;
            x=x*10;
        }
        else break;
    }

    return (num==i+1);

}

int main()
{
    string str="NihalAndUma11";
    isEqual(str)?cout<<"\nYes, True.\n":cout<<"\nNo, False\n";
}
