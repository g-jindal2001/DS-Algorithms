#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int longestCommonSubstringLength(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    int maxVal = 0;

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }

            if (j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = 0;
            }

            maxVal = max(maxVal, dp[i][j]);
        }
    }

    return maxVal;
}

string longestCommonSubstring(string s1, string s2, int m, int n)
{
    string dp[m + 1][n + 1];
    string maxString = "";

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = "";
            }

            if (j == 0)
            {
                dp[i][j] = "";
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = "";
            }

            if (maxString.length() < dp[i][j].length())
            {
                maxString = dp[i][j];
            }
        }
    }

    reverse(maxString.begin(), maxString.end());

    return maxString;
}

int main()
{
    string a = "abcdxyz";
    string b = "xyzabcd";

    cout << longestCommonSubstring(a, b, a.length(), b.length());

    // /cout << lcs(a, b, a.length(), b.length());
}