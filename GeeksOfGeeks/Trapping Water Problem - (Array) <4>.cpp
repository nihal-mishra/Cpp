#include<iostream>
using namespace std;

int main()
{
    int arr[] ={ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int len = sizeof(arr)/sizeof(*arr);
    int lmax[len];
    int rmax[len];
    int water=0;
    int m = arr[0];
    for(int i=0;i<len;i++)
    { 
        if(m<arr[i])
        {
            m=arr[i];
        }
        lmax[i]=m;
    }
    m=arr[len-1];
    for(int i=len-1;i>=0;i--)
    {
        if(m<arr[i])
        {
            m=arr[i];
        }
        rmax[i]=m;
    }
    for(int i=0;i<len;i++)
    {
        int mini = min(lmax[i],rmax[i]);
        water = water + (mini-arr[i]);
    }
    cout<<endl<<"Water that can be trapped :: "<<water<<endl;
}