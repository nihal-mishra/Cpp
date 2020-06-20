#include<iostream>
using namespace std;

void sub(string str, string curr, int index)
{
    if(index==str.length())
    {
        if(curr =="")
        {
            cout<<" \' \' ";
            return;
        }
        cout<<curr<<" ";
        return;
    }

    sub(str,curr,index+1);
    sub(str,curr+str[index],index+1);
}

int main()
{
    string str = "Nihal";
    string new_str = "";
    sub(str,new_str,0);
    cout<<endl;
}