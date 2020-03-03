/*
Retruns max sum you can achive when you start at (i,j)
and end at (row-1,column-1) and can move only in down or 
right direction
*/


#include<iostream>
using namespace std;
const int N=1003;
int r,c,a[N][N];

int go(int i, int j)
{
    if(i==r-1 && j==c-1)
    {
        return a[i][j];
    }
    int ans=0;

    if(i<r-1 && j<c-1)
    {
        ans = a[i][j] + max(go(i,j+1) , go(i+1,j));
    }
    else if(i==r-1)
    {
        ans = a[i][j] + go(i,j+1);
    }
    else
    {
        ans = a[i][j] + go(i+1,j);
    }
    return ans;
    
}


int main()
{
    cout<<"\nENTER ROW AND COLUMN :: ";
    cin>>r>>c;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }

    //PRINTING MATRIX
    cout<<"\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"MAX SUM :: "<<go(0,0)<<"\n";
}