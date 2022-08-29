#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int minLength = strs[0].length();
    return strs[0];
    // string smallestString = strs[0];
    // for (int i = 0; i < strs.size(); i++)
    // {
    //     int len = strs[i].length();
    //     if (len < minLength)
    //     {
    //         minLength = len;
    //         smallestString = strs[i];
    //     }
    // }
    // return smallestString;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string smallestString = longestCommonPrefix(strs);
    cout << smallestString;
    return 0;
}