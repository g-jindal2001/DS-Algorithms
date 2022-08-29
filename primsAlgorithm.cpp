#include <iostream>
#include <vector>

using namespace std;

#define V 6 // no of vertices in the graph

int minDistance(vector<int> &dist, vector<bool> &MST)
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] < min && MST[i] == false)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void findMST(int graph[V][V]) // This program is almost same if adjacency list is used instead of adjacency matrix just in the inner foor loop we iterate over the neigbours of the vertex instead of iterating over all vertex ( we also don't have to check edge existence if we are iterating over adjacency list)
{
    int parent[V];                // Stores parent node of visted nodes in MST which will be useful in constructing the MST
    vector<int> dist(V, INT_MAX); // Used to store the distances between different vertices (same as the table in Dijikstar's algorithm)
    vector<bool> MST(V, false);   // Used to store the visited status of nodes in MST

    parent[0] = -1; // start node has no parent
    dist[0] = 0;    // start node has value 0 since the distance to itself is 0

    for (int i = 0; i < V - 1; i++) // Form MST with V-1 edges (condition for MST)
    {
        int u = minDistance(dist, MST); // find the minimum distance vertex from the set of vertices not yet included in MST
        MST[u] = true;                  // add the vertex to MST

        for (int v = 0; v < V; v++)
        {
            /*
                3 constraints to be satisfied for an edge to be included in MST:
                1. Edge is present from u to v
                2. Edge is not included in MST already
                3. Edge weight is smaller than the current edge weight
            */

            if (graph[u][v] && MST[v] == false && graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = graph[u][v]; // replace current value of dist[v] with minimum value between those 2 vertices
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cout << "U->V: " << parent[i] << "->" << i << " Weight: " << graph[parent[i]][i] << "\n";
    }
}

int main()
{
    int graph[V][V] = {{0, 4, 6, 0, 0, 0},
                       {4, 0, 6, 3, 4, 0},
                       {6, 6, 0, 1, 8, 0},
                       {0, 3, 1, 0, 2, 3},
                       {0, 4, 8, 2, 0, 7},
                       {0, 0, 0, 3, 7, 0}};

    findMST(graph);

    return 0;
}