#include<iostream>
#include<map>
using namespace std;
int main()
{
    for(int r=10;r>0;r--)
    {
        for(int c=10;c>r;c--)
        {
            cout<<" ";
            for(int j=10;j>r;j--)
        {
            cout<<"#";
        }
        }
        
        cout<<"\n";

    }
}