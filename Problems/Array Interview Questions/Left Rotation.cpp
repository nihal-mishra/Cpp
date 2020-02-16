#include<iostream>
using namespace std;

void rotate(int *arr, int r, int len)
{

    for(int i=0;i<r;i++)
    {
        int temp=arr[0];
        for(int j=0;j<len;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[len-1]=temp;
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int len=sizeof(arr)/sizeof(*arr);
    int rotation;
    cout<<"\nEnter the no. of left rotations you want to perform :: ";
    cin>>rotation;
    cout<<"\n\nOrignal Array :: ";
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
    rotate(arr, rotation, len);
    cout<<"\n\nAfter Rotation Array :: ";
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
    cout<<"\n\n";
}