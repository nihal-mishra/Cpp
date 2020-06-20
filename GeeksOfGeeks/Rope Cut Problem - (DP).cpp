#include <iostream>
#include<climits>
using namespace std;

int maxCut(int n,int a,int b,int c, int dp[])
{
    if(n==0)
    return 0;

    if(n<0)
    return -1;

    if(dp[n]!=-10)
    return dp[n];


    dp[n] = max(maxCut(n-a,a,b,c,dp),max(maxCut(n-b,a,b,c,dp),maxCut(n-c,a,b,c,dp)));
    if(dp[n]==-1)
    return -1;

    return dp[n]+1;
}

int main()
{
    int n;
    cin>>n;
    int dp[100];
    for(int i=0;i<100;i++)
    dp[i]=-10;

    int res = maxCut(n,2,3,5,dp);
    cout<<endl<<res<<endl;
}