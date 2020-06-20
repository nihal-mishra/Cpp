#include <iostream>
using namespace std;

int maxCut(int n,int a,int b,int c)
{
    if(n==0)
    return 0;

    if(n<0)
    return -1;

    int res = max(maxCut(n-a,a,b,c),max(maxCut(n-b,a,b,c),maxCut(n-c,a,b,c)));
    if(res==-1)
    return -1;

    return res+1;
}

int main()
{
    int n;
    cin>>n;
    int res = maxCut(n,2,3,5);
    cout<<endl<<res<<endl;
}