#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int maxSubsetSum(vector<int> arr, int target, int n)
{
    if (n == 0 || target == 0)
    {
        return 0;
    }

    if (arr[n - 1] <= target)
    {
        return max(maxSubsetSum(arr, target, n - 1), arr[n - 1] + maxSubsetSum(arr, target - arr[n - 1], n - 1));
    }
    else
    {
        return maxSubsetSum(arr, target, n - 1);
    }
}

int maxSubsetSumDP(vector<int> arr, int target, int n) // alternate way as compared to maxSubsetSum
{
    bool dp[n + 1][target + 1];
    int min_num = INT_MAX;

    for (int i = 0; i < n + 1; i++) // initialization
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }

            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // till this point our table will be filled with true or false denoting whether a subset is possible for a array or not

    for (int i = 0; i < (target / 2) - 1; i++)
    {
        if (dp[n][i] = true) // checking the true values of first half of last row
        {
            cout << min_num << "\n";
            min_num = min(min_num, target - (2 * i));
        }
    }

    return min_num; // dp[n][target] would contain the subset with largest sum
}

int minimumSubsetDifference(vector<int> &arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    // return maxSubsetSumDP(arr, sum, arr.size());

    int maxSubset = maxSubsetSum(arr, sum / 2, arr.size());

    return sum - (2 * maxSubset);
}

int main()
{
    vector<int> arr = {1, 6, 5, 11};

    cout << minimumSubsetDifference(arr) << "\n"; // true refers to 1 and false refers to 0.

    return 0;
}