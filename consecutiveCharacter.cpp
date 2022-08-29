#include <iostream>
using namespace std;

int maxPower(string s)
{
    int count = 0;
    int max_count = 0;
    char previousChar = '\0';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == previousChar)
        {
            count++;
        }
        else
        {
            previousChar = s[i];
            count = 1;
        }
        max_count = max(max_count, count);
    }
    return max_count;
}

int main()
{
    string s = "leetcode";
    int power = maxPower(s);
    cout << power;
    return 0;
}