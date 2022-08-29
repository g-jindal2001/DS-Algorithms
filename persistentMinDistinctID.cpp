#include <bits/stdc++.h>

using namespace std;

int minDistinctId(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> umap;
    vector<pair<int, int>> sorted;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        umap[arr[i]]++;
    }

    for (auto it : umap) // for sorting a map convert it into a vector<pair<int, int>>
    {
        sorted.push_back(make_pair(it.second, it.first));
    }

    sort(sorted.begin(), sorted.end()); // this will sort according to first number

    for (int i = 0; i < n; i++)
    {
        if (sorted[i].first < k) // if frequnecy is less than k
        {
            k = k - sorted[i].first; // subtracting frequency from k;
            count++;
        }
        else // when we have removed k elements from arr
        {
            return sorted.size() - count;
        }
    }

    return sorted.size() - count;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 3, 2};
    int k = 3; // max 3 deletions

    int distinctIds = minDistinctId(v, 3);

    cout << distinctIds;

    return 0;
}