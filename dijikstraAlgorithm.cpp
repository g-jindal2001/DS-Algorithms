#include <limits.h>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(vector<int> &dist, vector<bool> &shortestPathTree)
{
    // Initialize min value
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++)
    {
        if (dist[i] <= min && shortestPathTree[i] == false)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(vector<int> dist, int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int startVertex)
{
    vector<int> dist(V, INT_MAX);            // Stores the distances of vertices from the source vertex
    vector<bool> shortestPathTree(V, false); // shortestPathTree[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from startVertex to i is finalized

    // Distance of source vertex from itself is always 0
    dist[startVertex] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to startVertex in the first iteration.
        int u = minDistance(dist, shortestPathTree);

        // Mark the picked vertex as processed
        shortestPathTree[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in shortestPathTree, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!shortestPathTree[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, V);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}