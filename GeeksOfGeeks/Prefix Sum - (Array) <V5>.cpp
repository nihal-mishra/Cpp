#include <iostream>
using namespace std;

void query(int *arr,int l, int r,int len)
{
    if(l>r || (r>len) || l>len)
    {
        cout<<endl<<"INVALID input"<<endl;
    }

    if(l==0)
    {
        cout<<endl;
        cout<<arr[r]<<endl;
    }
    else
    {
        cout<<endl;
        int sum = arr[r]-arr[l-1];
        cout<<sum<<endl;
    }
    
}

int main()
{
    int arr[] = {2,8,3,9,6,5,4};
    // PreCompution
    int len = sizeof(arr)/sizeof(*arr);
    for(int i=1;i<len;i++)
    {
        arr[i] = arr[i] + arr[i-1];
    }
    query(arr,0,2,len);
    query(arr,1,3,len);
    query(arr,2,6,len);

}