#include<iostream>
#include<vector>
using namespace std;

int main()
{
  vector<int> item;
  item.push_back(5);
  item.push_back(4);
  item.push_back(3);
  item.push_back(2);
  item.push_back(1);
  cout<<item.size()<<endl;
  for(int i=0;i<item.size();i++)
  {
       cout<<item[i]<<"\t";
  }

}