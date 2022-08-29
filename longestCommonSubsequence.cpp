#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int lcs(string s1, string s2, int m, int n) // returns length of longest common subsequence
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (s1[m - 1] == s2[n - 1]) // if both characters at end of string are same
    {
        return 1 + lcs(s1, s2, m - 1, n - 1); // we are adding one to lcs since we select that one character and recursively call function again
    }

    else // if both characters at end of string are different
    {
        return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
}

string lcsDPPrint(string s1, string s2, int m, int n) // print longest subsequence
{
    string dp[m + 1][n + 1];

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
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }

            else
            {
                dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

int lcsDPLength(string s1, string s2, int m, int n) // length of longest subsequence
{
    int dp[m + 1][n + 1];

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

    for (int i = 1; i < m + 1; i++) // starting from 1 since 1st row and 1st column is already intialized
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string a = "bl";
    string b = "yby";

    cout << lcsDPLength(a, b, a.length(), b.length());

    // /cout << lcs(a, b, a.length(), b.length());
}