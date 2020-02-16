#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> A = {10,20,50,80,60,100};
int main()
{
    int ij;
    cout<<"\n";
    vector<int>::iterator i=A.begin();
    for(i=A.begin();i!=A.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    
    
}
