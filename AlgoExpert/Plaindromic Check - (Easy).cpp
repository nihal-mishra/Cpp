#include<iostream>
using namespace std;

bool plaindromicCheck(char str[])
{
    int len = strlen(str);
    int left = 0;
    int right = len-1;

    for(int i=0; i<=len/2; i++)
    {
        if(str[left] == str[right])
        {
            left +=1;
            right -= 1;
        }
        else return false;
    }

    return true;
}

int main()
{
    char st[] =  "nihalahin";
    if(plaindromicCheck(st))
        cout<<"\n\nIt is a Plandromic String\n\n";
    else
        cout<<"\n\nIt is not a Plandrominc String\n\n";
}