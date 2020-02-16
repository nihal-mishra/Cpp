#include<iostream>
#include<climits>
using namespace std;

int MAXsum(int arr[],int len)  // O(n^2)
{
    int maxsum=INT_MIN;

    for(int index=0;index<len;index++)
    {
        int sum=0;
        for(int SAsize=1;SAsize<=len;SAsize++)
        {
            if(index+SAsize > len) break;
            sum+=arr[index+SAsize-1];
            maxsum=max(sum,maxsum);
        }
    }
    return maxsum;
}

/*
int MAXsum(int arr[],int len) // O(n^3)
{

   int maxsum=INT_MIN; 
   for(int subarraysize = 1 ; subarraysize<=len; ++subarraysize)
   {
       for(int srt = 0 ; srt<len ; ++srt)
       {
           if((subarraysize + srt)>len)
           break;
           int sum=0;
           for(int i=srt ; i<(srt+subarraysize) ; ++i)
           {
               sum=arr[i]+sum;
           }
           maxsum=max(maxsum,sum);
       }
   }
   return maxsum;

}
*/

int main()
{
    int arr[] = {112,1,243,-125,234,-343,-10,100,234,-43};
    int len=sizeof(arr)/sizeof(arr[0]);
    int sum = MAXsum(arr,len);
    cout<<"\n\nMAX sum of subarray :: "<<sum<<"\n\n";
}