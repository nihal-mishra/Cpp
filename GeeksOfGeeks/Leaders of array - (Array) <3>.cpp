#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> stk;
    int arr[]={5,2,6,7,65,64,21,56,10};
    int len=sizeof(arr)/sizeof(*arr);
    int max=arr[len-1];
    stk.push(max);
    //Naive method - O(n^2) 
    //Efficient method is to traverse from right side - O(n)
    for(int i=len-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
            stk.push(arr[i]);
            max=arr[i];
        }
    }
 //Just to print in same order as of array I have used stack.
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop(); 
    }
}