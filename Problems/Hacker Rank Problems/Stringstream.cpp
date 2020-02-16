/*Sample Input
23,4,56
 OR
123,456n23,86g567

Sample Output
23
4
56
 OR
 123
456
23
86
567
*/

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector<int> parseInts(string str)
{
    stringstream s(str);
    int num;
    char chr;
    vector<int> n;
    while(s>>num)
    {
        n.push_back(num);
        s>>chr;
    }
    return n;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
}
