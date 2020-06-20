#include<iostream>
using namespace std;


void printsub(string input,string output,int &i)
{
    if(input.length()==0)
    {
        cout<<output<<"\n";
        i++;
        return;
    }
    printsub(input.substr(1),output,i);
    printsub(input.substr(1),output+ input[0],i);
}

int main()
{
    string input;
    cin>>input;
    int i=0;
    string output = "";
    printsub(input,output,i);
    cout<<"\nSize "<<i<<endl;
    cout<<"\n";

}