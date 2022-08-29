#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int memoization[100][1000]; // taking arbitary value of size as 100 and capacity of knapsack as 1000 (can be changed)

int knapsackRecursion(vector<int> &weights, vector<int> &values, int capacity, int n) // only recursion
{
    if (n == 0 || capacity == 0) // base condition
    {
        return 0;
    }

    if (weights[n - 1] <= capacity)
    {
        return max(values[n - 1] + knapsackRecursion(weights, values, capacity - weights[n - 1], n - 1), knapsackRecursion(weights, values, capacity, n - 1));
    }

    else
    {
        return knapsackRecursion(weights, values, capacity, n - 1);
    }
};

int knapsackMemoization(vector<int> &weights, vector<int> &values, int capacity, int n) // memoization = recursion + table
{
    if (memoization[n][capacity] != -1)
    {
        return memoization[n][capacity];
    }

    if (weights[n - 1] <= capacity)
    {
        return memoization[n][capacity] = max(values[n - 1] + knapsackMemoization(weights, values, capacity - weights[n - 1], n - 1), knapsackMemoization(weights, values, capacity, n - 1));
    }

    else
    {
        return memoization[n][capacity] = knapsackMemoization(weights, values, capacity, n - 1);
    }
};

int knasackDP(vector<int> &weights, vector<int> &values, int capacity, int n) // only table (no recursion)
{
    int dp[n + 1][capacity + 1];

    for (int i = 0; i < n + 1; i++) // Intilializing 1st row and 1st column with zero (same as base condition of recursion)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // logic same as memoization and recursion, just replace n and capacity with i and j inside inner for loop
    for (int i = 1; i < n + 1; i++) // for loop starting at one since it we have already intialized 1st row and column with 0's
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7, 8};

    memset(memoization, -1, sizeof(memoization)); // used to fill the matrix with -1

    int capacity = 7;
    int n = weights.size();

    int value = knapsackRecursion(weights, values, capacity, n);
    int value2 = knapsackMemoization(weights, values, capacity, n);
    int value3 = knasackDP(weights, values, capacity, n);

    cout << value << "\n";
    cout << value2 << "\n";
    cout << value3;

    return 0;
}