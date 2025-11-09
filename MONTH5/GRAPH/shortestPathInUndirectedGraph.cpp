#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestPathInUndirectedGraph(int src, vector<vector<int>> &edges, int n, int destination)
{
    // Step 1: Build adjacency list

    vector<vector<int>> adj(n);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(src);
    visited[src] = true;

    // Step 2: BFS with parent tracking
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int neighbor : adj[front])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = front;
                q.push(neighbor);
            }
        }
    }//

    // Step 3: Reconstruct path from destination to src
    vector<int> path;
    int current = destination;

    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    // Step 4: Reverse path to get src -> destination
    reverse(path.begin(), path.end());

    cout << "Shortest Path Length " << path.size() - 1 << endl;
    return path;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {4, 9}, {2, 5}, {6, 7}, {7, 6}, {8, 9}, {9, 8}};

    int n = 10;
    int src = 1;
    int dest = 9;

    vector<int> ans = shortestPathInUndirectedGraph(src, edges, n, dest);

    if (ans.empty())
    {
        cout << "No path exists from " << src << " to " << dest << endl;
    }
    else
    {
        cout << "Shortest Path from " << src << " to " << dest << ":\n";
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
