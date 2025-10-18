#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &tempans, int n)
{
    visited[n] = true;
    tempans.push_back(n);

    // har conneccted node ke liye reccurisve call
    for (auto neighbour : adjList[n])
    {
        if (!visited[neighbour])
        {
            dfs(adjList, visited, tempans, neighbour);
        }
    }
}

vector<vector<int>> depthSearchFirst(int node, int e, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;

    // Prepare adjacentLsit
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); // Unordered Graph
    }

    // Track of visited or not
    unordered_map<int, bool> visited;

    // Call DFS for all node if not visited and loop for broken component
    vector<vector<int>> ans;
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    int vertex = 10;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {6, 7}, {7, 6}, {8, 9}, {9, 8}};

    vector<vector<int>> dfsResult = depthSearchFirst(vertex, edges.size(), edges);

    cout << "DFS Traversal: " << endl;
    int compCount = 0;
    for (auto i : dfsResult)
    {
        cout << compCount + 1 << " component" << endl;
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
        compCount = compCount + 1;
    }
    cout << endl;
    return 0;
}