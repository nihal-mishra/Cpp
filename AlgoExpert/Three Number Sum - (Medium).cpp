#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector< vector<int> > ThreeNumberSum(int nums[], int len, int targetSum)
{
    vector< vector<int> > resultLists = {};
    int current_sum = INT_MIN;
    int count = 0;
    sort(nums, nums+len);
    
    for(int i = 0; i < len; i++)
    {
        int current_num = nums[i];
        int left = i + 1;
        int right = len - 1;

        while(left < right)
        {
            current_sum = nums[left] + nums[right] + current_num;
            
            if(current_sum == targetSum)
            {  
                resultLists.push_back({current_num, nums[left], nums[right]});
                --right;
                ++left;
            }
            else if(current_sum < targetSum)
                ++left;
            else if(current_sum > targetSum) 
                --right;
        }
    }
    return resultLists;
}

int main()
{
    int numbers[] = {12, 3, 1, 2, -6, 5, -8, 6};
    int targetSum = 0;
    int len = sizeof(numbers)/sizeof(*numbers);
    vector<vector<int> > result = ThreeNumberSum(numbers, len, targetSum);
    cout<<endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout<<i+1<<" :->  ";
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl;
}