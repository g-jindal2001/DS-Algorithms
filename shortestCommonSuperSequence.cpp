#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string findLCS(string s1, string s2, int m, int n) // print longest common subsequence
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

string shortestCommonSupersequence(string str1, string str2) // print shortest common supersequence
{
    string ans = "";
    string lcs = findLCS(str1, str2, str1.length(), str2.length());
    // cout << lcs << "\n";

    int p1 = 0, p2 = 0;

    for (char c : lcs)
    {
        while (str1[p1] != c)
        {
            ans = ans + str1[p1];
            p1++;
        }

        while (str2[p2] != c)
        {
            ans = ans + str2[p2];
            p2++;
        }

        ans = ans + c; // Add LCS-char and increment both ptrs
        p1++;
        p2++;
    }

    ans = ans + str1.substr(p1) + str2.substr(p2);
    return ans;
}

int shortestCommonSupersequenceLength(string str1, string str2) // length of shortest common supersequence
{
    string lcs = findLCS(str1, str2, str1.length(), str2.length());

    return str1.length() + str2.length() - lcs.length();
}

int main()
{
    string a = "abcdgh";
    string b = "abedfhr";

    cout << shortestCommonSupersequence(a, b);

    // /cout << lcs(a, b, a.length(), b.length());
}