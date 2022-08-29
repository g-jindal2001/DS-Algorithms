#include <iostream>
#include <map>
#include <list> // list in cpp is equal to doubly linked list
#include <queue>

using namespace std;

class Graph
{
    map<int, list<int>> adjLists; // we can also use a vector<int> here instead of list<int>

public:
    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // this additional line signifies that the graph is undirected otherwise if the graph is directed then the graph will be directed
    }

    void BFS(int startVertex)
    {
        map<int, bool> visited;
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex); // pushing starting vertex into queue

        while (!q.empty()) // while queue is not empty
        {
            int currVertex = q.front();
            cout << "Visited " << currVertex << " ";
            q.pop();

            for (int neighbour : adjLists[currVertex]) // get each neighbour of the current vertex
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    void dfs_helper(int startVertex, map<int, bool> &visited) // we use recursion because in dfs we want to go deep inside the graph and explore the nodes in that branch first instead of expolring all the neigbouring nodes at once like in bfs
    {
        visited[startVertex] = true;
        cout << "Visited " << startVertex << " ";

        for (int neighbour : adjLists[startVertex])
        {
            if (!visited[neighbour])
            {
                dfs_helper(neighbour, visited);
            }
        }
    }

    void DFS(int startVertex)
    {
        map<int, bool> visited;
        for (auto node : visited) // Intializing all the nodes to false
        {
            node.second = false;
        }

        dfs_helper(startVertex, visited);
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal: ";
    g.BFS(2);
    cout << "\n";
    cout << "DFS traversal: ";
    g.DFS(2);

    return 0;
}