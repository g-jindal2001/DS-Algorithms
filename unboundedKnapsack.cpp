#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(vector<int> &weights, vector<int> &values, int capacity, int n)
{
    if (n == 0 || capacity == 0) // base condition
    {
        return 0;
    }

    if (weights[n - 1] <= capacity) // include
    {
        return max(values[n - 1] + unboundedKnapsack(weights, values, capacity - weights[n - 1], n), unboundedKnapsack(weights, values, capacity, n - 1)); // capacity will decrease if selected item is put in knapsack
    }
    else
    {
        return unboundedKnapsack(weights, values, capacity, n - 1);
    }
}

int rodCuttingProblem(vector<int> &length, vector<int> &price, int totalLength, int cut) // length = capacity, cut == n (variable which we will try to reduce)
{
    if (totalLength == 0 || cut == 0)
    {
        return 0;
    }

    if (length[cut - 1] <= totalLength)
    {
        return max(price[cut - 1] + rodCuttingProblem(length, price, totalLength - length[cut - 1], cut), rodCuttingProblem(length, price, totalLength, cut - 1));
    }

    else
    {
        return rodCuttingProblem(length, price, totalLength, cut - 1);
    }
}

int coinChangeProblem(vector<int> price, int sum, int n)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
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

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (price[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - price[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int coinChangeProblem2(vector<int> price, int sum, int n)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1; // or INT_MAX is also ok
            }

            if (j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (price[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - price[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    // vector<int> weights = {15, 5, 10};
    // vector<int> values = {25, 30, 15};

    // int capacity = 100;
    // int n = weights.size();

    vector<int> coin = {1, 2, 3};
    int sum = 5;

    cout << coinChangeProblem2(coin, sum, coin.size());

    // cout << unboundedKnapsack(weights, values, capacity, n);
}