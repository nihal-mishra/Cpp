#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,5,6,7};
    int size = sizeof(arr)/sizeof(*arr);
    cout<<size<<endl;
    for(int i=0;i<size/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}