#include<iostream>
#include<stack>
/*Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".*/
using namespace std;
int balancedStringSplit(string s) {
        
        int count=0;
        int ans=0;
        stack<char> stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty()||stk.top()==s[i])
            {
                stk.push(s[i]);
                count++;
            }
            else
            {
                stk.pop();
                    count--;
            }
            if(stk.empty() && count==0)
            {
                ++ans;
            }
        }
        return ans;
    }
int main()
{
    string input;
    cin>>input;
    int ans=balancedStringSplit(input);
    cout<<"\n"<<ans<<endl;
}