#include<iostream>
using namespace std;

int profit(int arr[],int len)
{
    int profit=0;
    for(int i=0;i<len-1;i++)
    {
        if(arr[i]<arr[i+1])
        {
            profit = profit+ (arr[i+1]-arr[i]);
        }
        else
        {
            profit = profit + 0;
        }
    }
    return profit;
}

int main()
{
    int arr[] = {10,5,3,12,100,103};
    int len = sizeof(arr)/sizeof(*arr);
    cout<<"Profit made Rs."<<profit(arr,len)<<endl; 
}