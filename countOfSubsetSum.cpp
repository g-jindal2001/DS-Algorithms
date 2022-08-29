#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int subsetSumDP(vector<int> arr, int target, int n)
{
    int dp[n + 1][target + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
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

    for (int i = 1; i < n + 1; i++) // starting from 1 since 1st row and 1st column is already intialized
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] <= j) // include
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }

            else // exclude
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

int main() // problem can be rephrased as finding a subset with sum = sum of array / 2
{
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int target = 10;

    cout << subsetSumDP(arr, target, arr.size()) << "\n";
}