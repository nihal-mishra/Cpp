#include<iostream>
#include<vector>
#include<algorithm>
#define vec vector<int>

using namespace std;

vec Difference(vec &list1, vec &list2)
{
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int pointer1 = 0;
    int pointer2 = 0;
    int lowest_difference = INT_MAX;
    int Difference_number1 = INT_MAX;
    int Difference_number2 = INT_MAX;

    // {-1, 3, 5, 10, 20, 28}   {15, 17, 26, 134, 135};
    

    for(int i=0; i<(list1.size()+list2.size()); i++)
    {
        int Current_Difference = abs(list1[pointer1] - list2[pointer2]);
        if(Current_Difference < abs(lowest_difference))
        {
            lowest_difference = Current_Difference;
            Difference_number1 = list1[pointer1];
            Difference_number2 = list2[pointer2];
        }

        if(list1[pointer1] == list2[pointer2])
            return {list1[pointer1], list2[pointer2]};

        else
        {
            if(list1[pointer1] < list2[pointer2])
                ++pointer1;

            else if(list1[pointer1] > list2[pointer2])
                ++pointer2;
        }
    }

    return {Difference_number1, Difference_number2};
}

int main()
{
    vec nums1 = {-1, 5, 10, 20, 28, 3};
    vec nums2 = {26, 134, 135, 15, 17};
    vec res = Difference(nums1, nums2);
    cout<<"1st -> "<<res[0]<<"\n2nd -> "<<res[1]<<endl;
    cout<<"Differenece -> "<<abs(res[0] - res[1])<<endl<<endl;
}