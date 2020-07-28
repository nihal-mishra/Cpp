#include<iostream>
using namespace std;

int fibonacci(int target)
{
    int first = 0;
    int second = 1;

    for(int i = 0; i<target; i++)
    {
        int temp = first + second;
        first = second;
        second = temp;
    }

    return second;
}

int main()
{
    int n = 10;
    int nth = fibonacci(n);
    cout<<endl<<n<<"th fibonacci is "<<nth<<endl<<endl;
}