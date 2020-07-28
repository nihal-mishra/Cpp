#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void TwoSumNN(int *arr, int len, int target)    // O(N^2)
{   int x=0,y=0,sum=INT_MIN;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(i==j)
            break;

            sum=arr[i]+arr[j];
            if(sum==target)
            {
                x=arr[i];
                y=arr[j];
                break;
            }
        }
        if(sum==target)
        {
            break;
        }
    }
    cout<<endl<<y<<" + "<<x<<" = "<<target<<endl;
}

void TwoSumN(int *arr, int len, int target)      // Time - O(N) and Space - O(N)
{
    unordered_map<int,bool> mp;
    int find=INT_MIN;
    int cur=INT_MIN;

    for(int i=0;i<len;i++)
    {
        cur=arr[i];

        if(mp.find(cur)==mp.end()) // NOT PRESENT
        {
            mp[cur] = true;
        }
        // target = cur + find;
        // find = target - cur
        find = target - cur;
        if(mp.find(find) != mp.end() && find!=cur)   // hence means present
        {
            cout<<endl<<find<<" + "<<cur<<" = "<<target<<endl;
            break;
        }
    }
}

void TwoSumNlogN(int *arr, int len, int target)  // Time - O(NlogN)
{
    sort(arr,arr+len);
    int l=0;
    int r=len-1;

    for(int i=0;i<len;i++)
    {
       int sum = arr[l] + arr[r];

       if(sum>target)
       {
           --r;
       }

       if(sum<target)
       {
           ++l;
       }

       if(sum==target)
       {
           cout<<endl<<arr[l]<<" + "<<arr[r]<<" = "<<target<<endl;
           break;
       }
    }

}

int main()
{
    int arr[] = {3,5,-4,8,11,1,-1,6};
    int target;
    cin>>target;
    int len = sizeof(arr)/sizeof(*arr);

    TwoSumNN(arr,len,target);       //      Time - O(N*N)  || Space - O(1)
    TwoSumN(arr,len,target);        //      Time - O(N)  || Space - O(N)
    TwoSumNlogN(arr,len,target);    //      Time - O(NlogN)  || Space - O(1)
}