#include <bits/stdc++.h>
using namespace std;

/*Topological sort only valid for directed Acyclic graph
Linear ordering of vertices such that for every edge u-> v  such that u appear before v

Valid topological sort nahi nikal pa rahe to graph mai cycle exist karti hai
*/

void topologicalLogic(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, stack<int> &s)
{
    visited[node] = true;

    // Check for neighbour
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topologicalLogic(adj, visited, neighbour, s);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)
{
    // Create adj List

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // Directed graph
    }

    //// Track Visited
    unordered_map<int, bool> visited;

    stack<int> s;

    // Check For All Component Graph
    for (int i = 0; i < n; i++)
    {
        // Create Stack for Topological order
        if (!visited[i])
        {
            topologicalLogic(adj, visited, i, s);
        }
    }

    vector<int> ans;

    // Storing answer from Stack
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
int main()
{
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};

    vector<int> ans = topologicalSort(edges, 6, 5);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}