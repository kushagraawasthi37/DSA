#include <bits/stdc++.h>
using namespace std;

bool checkCycle(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited, int node)
{

    visited[node] = true;
    DFSvisited[node] = true;

    // check for all neighbour
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (checkCycle(adj, visited, DFSvisited, neighbour))
            {
                return true;
            }
        }

        else if (DFSvisited[neighbour])
        {
            return true;
        }
    }

    DFSvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // Create adjacemcy List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v); // Directed graph
    }

    // Track visited node
    unordered_map<int, bool> visited;
    // Track node currently In DFSVisited
    unordered_map<int, bool> DFSVisited;

    // For all Node including component graph
    for (int i = 0; i < n; i++)
    {
        // Node not visited
        if (!visited[i])
        {
            bool cycleFound = checkCycle(adj, visited, DFSVisited, i);
            if (cycleFound)
            {
                return 1;
            }
        }
    }

    return 0;
}
int main()
{
    int n = 4;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}}; // Cycle exists
    cout << detectCycleInDirectedGraph(n, edges) << endl;            // Output: 1
}
