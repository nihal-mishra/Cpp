#include<iostream>
using namespace std;

int countOnes(int number)
{   int count=0;
    while(number>0)
    {
        number=number & (number << 1);
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int count=0;
    count=countOnes(n);
    cout<<"\nNo. of 1s :: "<<count<<endl;
}