#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int noOfTimesS2OccursAsASubsequenceInS1(string s1, string s2, int m, int n)
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
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string a = "geeksforgeeks";
    string b = "gks";

    cout << noOfTimesS2OccursAsASubsequenceInS1(a, b, a.length(), b.length());

    // /cout << lcs(a, b, a.length(), b.length());
}