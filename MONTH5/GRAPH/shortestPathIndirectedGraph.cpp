#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

void topoSort(unordered_map<int, list<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &s, int n)
{
    visited[n] = true;
    for (auto neighbour : adj[n])
    {
        if (!visited[neighbour.first])
        {
            topoSort(adj, visited, s, neighbour.first);
        }
    }
    s.push(n);
}

vector<int> shortestPathInDirectedAcyclicGraph(int src, int des, vector<vector<pair<int /*node*/, int /*Weight*/>>> &edges, int n)
{
    // Create Ajacency List
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        // Weighted Graph
        int u = edges[i][0].first;
        pair<int, int> v = edges[i][1];

        adj[u].push_back(v); // Directed Graph
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    // Step 1 Calculate topological Sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(adj, visited, s, i);
        }
    }

    // Craete Distance array with Infinite Value
    vector<int> distance(n, INT32_MAX);

    // If source node is not given intilise it with 0
    distance[src] = 0;
    
    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (distance[top] != INT32_MAX)
        {
            for (auto i : adj[top])
            {
                if (distance[top] + i.second < distance[i.first])
                {
                    distance[i.first] = distance[top] + i.second;
                }
            }
        }
    }

    // return distance[des] if you want only the shortest path to destination
    return distance;
}

int main()
{
    int n = 6;
    vector<vector<pair<int, int>>> edges = {
        {{0, 0}, {1, 2}},
        {{0, 0}, {4, 1}},
        {{1, 0}, {2, 3}},
        {{4, 0}, {2, 2}},
        {{2, 0}, {3, 6}},
        {{4, 0}, {5, 4}},
        {{5, 0}, {3, 1}}};

    int src = 0;
    vector<int> result = shortestPathInDirectedAcyclicGraph(src, -1, edges, n);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;
}
