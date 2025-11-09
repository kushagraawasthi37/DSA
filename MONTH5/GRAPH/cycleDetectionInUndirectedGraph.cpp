#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (visited[neighbour] && neighbour != parent[front])
            {
                return true; // Cycle found
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false; // No cycle
}

string cycleDetectionBFS(vector<vector<int>> &edges, int n)
{

    // Create Adjacent List
    unordered_map<int, list<int>> adjList;

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    // Keep Track of visited
    unordered_map<int, bool> visited;

    // Check for all Node consider disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicBFS(i, adjList, visited))
            {
                return "Yes, cycle exists (BFS)";
            }
        }
    }

    return "No cycle exists (BFS)";
}

// --//-------------- DFS Cycle Detection ---------------- //

bool isCyclicDFS(int node, int parent, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    // Check for all neighbour
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            if (isCyclicDFS(neighbour, node, adjList, visited))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true; // Back edge -> cycle exist
        }
    }

    return false;
}

string cycleDetectionDFS(vector<vector<int>> &edges, int n)
{
    // Create Adjacent List
    unordered_map<int, list<int>> adjList;

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    unordered_map<int, bool> visited;

    // Check for all Node consider disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDFS(i, -1, adjList, visited))
            {
                return "Yes, cycle exists (DFS)";
            }
        }
    }

    return "No cycle exists (DFS)";
}

// ---------------- Main Test ---------------- //

int main()
{
    // Sample graph with a cycle
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}};
    int n1 = 4;

    // Sample graph with no cycle
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}};
    int n2 = 4;

    cout << "Graph 1:\n";
    cout << cycleDetectionBFS(edges1, n1) << endl;
    cout << cycleDetectionDFS(edges1, n1) << endl;

    cout << "\nGraph 2:\n";
    cout << cycleDetectionBFS(edges2, n2) << endl;
    cout << cycleDetectionDFS(edges2, n2) << endl;

    return 0;
}
