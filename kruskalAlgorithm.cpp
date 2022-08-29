#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sizeVector(N); // size vector is used to determine whether set 1 get inserted into set 2 or vice-versa

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path Compression
}

void union_op(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (sizeVector[a] < sizeVector[b])
        {
            parent[a] = b;
            sizeVector[b] += sizeVector[a];
        }
        else
        {
            parent[b] = a;
            sizeVector[a] += sizeVector[b];
        }
    }
}

// bool comparator(vector<int> a, Edge b)
// {
//     return a.wt < b.wt;
// }

void Kruskals(vector<vector<int>> &edge_List)
{
    sort(edge_List.begin(), edge_List.end());

    int total_cost = 0;
    for (auto i : edge_List)
    {
        int weight = i[2];
        int u = i[0];
        int v = i[1];

        int parent1 = find_set(u);
        int parent2 = find_set(v);

        if (parent1 == parent2)
        {
            continue;
        }
        else
        {
            cout << u << " " << v << "\n";
            total_cost += weight;
            union_op(parent1, parent2); // UNION of 2 sets
            // mst.push_back(edge_List[j]); // pushing the edge to our MST
        }
    }

    cout << "Total cost: " << total_cost;
}

int main()
{
    long long weight, cost, minCost;
    vector<vector<int>> edges;

    for (int i = 0; i < N; i++) // initialize the array groups
    {
        parent[i] = i;
        sizeVector[i] = 1;
    }

    edges.push_back({1, 2, 5});
    edges.push_back({2, 3, 6});
    edges.push_back({4, 3, 2});
    edges.push_back({1, 4, 9});
    edges.push_back({3, 5, 5});
    edges.push_back({5, 6, 10});
    edges.push_back({6, 7, 7});
    edges.push_back({7, 8, 1});
    edges.push_back({8, 5, 1});

    Kruskals(edges);

    return 0;
}