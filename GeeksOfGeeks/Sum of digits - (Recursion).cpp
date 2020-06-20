#include<iostream>
using namespace std;

int SUM(int n)
{
    if(n<10)
    return n;

    return (SUM(n/10)+(n%10));
}

int main()
{
    int num;
    cin>>num;
    int s;
    s = SUM(num);
    cout<<"SUM : "<<s<<endl;
}