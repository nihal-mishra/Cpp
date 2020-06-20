#include<iostream>
#include<vector>
using namespace std;

int k=0;
int subs(string input, string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string smallstr=input.substr(1);
    int smallOutputSize=subs(smallstr,output);
    for(int i=0;i<smallOutputSize;i++)
    {
        output[i+smallOutputSize] = input[0]+output[i];
    }
    return 2*smallOutputSize;
}

int main()
{
    string input;
    cin>>input;
    
    string out[1000];
    int count=subs(input, out);
    cout<<endl;
    cout<<"Size :: "<<count<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<out[i]<<endl;
    }
    cout<<"\n\n";
}