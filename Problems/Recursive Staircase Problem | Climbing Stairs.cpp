#include <iostream>
using namespace std;

int Recursion(int i) //O(2^N)
{
    if(i<0)
    return 0;

    if(i==0)
    return 1;

    return Recursion(n-1 ,cache) + Recursion(n-2 ,cache) + Recursion(n-3 ,cache);
}

int TopDown(int n,int *cache)  // Top down approch----- O(N)  || Space :: O(N)
{
    if(n<0)
    {
        return 0;
    }

    if(cache[n]!=-1)
    {
        return cache[n];
    }

    return cache[n]= TopDown(n-1,cache) + TopDown(n-2,cache) + TopDown(n-3,cache);
}

int main()
{
    int top;
    cin>>top;
    int arr[top];
    for(int i=0;i<=top;i++)
    {
        arr[i]=-1;
        //cout<<arr[i]<<endl;

    }
    int ways;
    ways=TopDown(top,arr);
    cout<<"\nTotal no. of ways : "<<ways<<endl;



}