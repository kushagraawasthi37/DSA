#include <bits/stdc++.h>
using namespace std;

/**************Cycle detection using BFS****************/

// If valid topological order using kahns algorithm then no cycle present

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Create Adjacent List
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v); // Directed Graph
    }

    // Calculating Indegree

    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i)
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    // Track count->  for valid Topological Order count =number of node
    int count = 0;

    // Pushing element with 0 Indegree in queue
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // Increment count
        count++;

        for (auto neighbour : adj[front])
        {
            // Neighbour ki indegree kam karo
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // Cycle Not exist->Valid topological sort
    if (count == n)
        return 0;

    // Cycle exist
    return 1;
}

int main()
{
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1} // Creates a cycle
    };

    int n = 4;

    if (detectCycleInDirectedGraph(n, edges))
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}