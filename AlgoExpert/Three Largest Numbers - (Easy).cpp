#include<iostream>
#include<vector>
using namespace std;

vector<int> ThreeLargestNumbers(vector<int> &nums)
{
    int len = nums.size();
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    int third_largest = INT_MIN;

    for(int i = 0; i<len-1; i++)
        if(nums[i] > largest)
            largest = nums[i];

    for(int i = 0; i<len-1; i++)
        if(nums[i] < largest && nums[i]> second_largest)
            second_largest = nums[i];

    for(int i = 0; i<len-1; i++)
        if(nums[i] < largest && nums[i] < second_largest && nums[i] > third_largest)
            third_largest = nums[i];
            
    vector<int> result = {third_largest, second_largest, largest};
    return result;
}

int main()
{
    vector<int> numbers = {141, 1, 7, 17, -7, -17, 27, 18, 541, 8, 7};
    vector<int> result = ThreeLargestNumbers(numbers);
    cout<<endl;
    for(int element : result)
    {
        cout<<" "<<element;
    }
    cout<<endl;
}