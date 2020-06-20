#include <iostream>
using namespace std;

int maxSum(int *arr,int k,int len)
{
    int cur=0;
    int m=INT_MIN;

    for(int i=0;i<len;i++)
    {
        cur=cur+ arr[i];
        if(i>=k-1)
        {
            m = max(m,cur);
            cur = cur - arr[i-(k-1)];
        }
    }
    return m;
}

int main()
{
    int arr[] = {4,2,1,7,8,1,2,8,1,0};
    int len = sizeof(arr)/sizeof(*arr);
    int k=3;
    int max=maxSum(arr,k,len);
    cout<<endl;
    cout<<"MAX sum of a subarray of size"<<k<<"is :: "<<max;
    cout<<endl;
}