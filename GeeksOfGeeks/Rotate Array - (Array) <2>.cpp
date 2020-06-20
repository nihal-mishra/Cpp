#include<iostream>
using namespace std;
int arr[]= {1,2,3,4,5,6,7,8,9};
void reverse(int *arr,int s, int e)
{
    while(!(s>e) || s==e)
    {
        int temp=arr[e];
        arr[e]=arr[s];
        arr[s]=temp;
        s++;
        e--;
    }
}

int main()
{
    int len=sizeof(arr)/sizeof(*arr);
    int shift;
    cin>>shift;
    reverse(arr,0,shift-1);
    reverse(arr,shift,len-1);
    reverse(arr,0,len-1);
    cout<<endl;
    for(int i=0;i<len;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}