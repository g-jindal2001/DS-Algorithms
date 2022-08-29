#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
    Problem statement - given arr = {2, 3, 7, 8, 10} find subset whose sum adds up to given target
    eg target = 17 , subset = {2,7,8}, output = true
    eg target = 7, subset = {7}, output = true
    eg target = 6, subset = {}, output = false
*/

bool subsetSumDP(vector<int> arr, int target, int n)
{
    bool dp[n + 1][target + 1];

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

    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = true;

    // // If sum is not 0 and set is empty,
    // // then answer is false
    // for (int i = 1; i <= target; i++)
    //     dp[0][i] = false;

    for (int i = 1; i < n + 1; i++) // logic
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; // Here instead of max we use || here as inputs are boolean instead of int
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

int main()
{
    vector<int> arr1 = {2, 3, 7, 8, 10};

    int target = 15;
    int n = arr1.size();

    bool value = subsetSumDP(arr1, target, n); // we ignore values vector and replace weights array in knapsack with given array, capacity with target and n remains same

    cout << value << "\n"; // true refers to 1 and false refers to 0.

    return 0;
}