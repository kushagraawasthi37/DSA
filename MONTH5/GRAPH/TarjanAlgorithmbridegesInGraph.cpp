#include <bits/stdc++.h>
using namespace std;

/*Edge Jisko remove karne par no of connected component  badh jaye */
//  Tarjan’s Algorithm used to find bridge in undirected Graph

void checkBridge(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &disc, vector<int> &low, int parent, int node, int &timer, vector<vector<int>> &result)
{
    visited[node] = true;

    // Start mai dono equal hi honge
    disc[node] = low[node] = timer;
    timer++;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
        {
            continue;
        }

        else if (!visited[neighbour])
        {
            checkBridge(adj, visited, disc, low, node, neighbour, timer, result);
            // Update low
            low[node] = min(low[node], low[neighbour]);

            // Check edge as bridge or not
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);

                // Update edge in result
                result.push_back(ans);
            }
        }
        else
        {
            // Back Edge Case
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int e)
{
    // Create Adjacency List

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected Graph
    }

    /*

         disc: when a node is first visited.

         low: lowest discovery time reachable from that node.

         timer: globally increasing timestamp.

         visited: to keep track of visited nodes.

         result: stores all bridges as pairs



         disc[u]:	Time when node u is first discovered in DFS
         low[u]:	Lowest discovery time node u can reach via back edges or subtree

    */

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int parent = -1;
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    // dfs
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            checkBridge(adj, visited, disc, low, parent, i, timer, result);
        }
    }

    return result;
}
int main()
{
    int n = 5, e = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}};

    vector<vector<int>> bridges = findBridges(edges, n, e);

    cout << "Bridges in the graph:\n";
    for (auto &bridge : bridges)
    {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}
