#include <bits/stdc++.h>
using namespace std;

/*Articulation Point are those node if they are removed then it will increase the component of graph */

void dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &low, vector<int> &disc, int parent, int node, vector<int> &atp, int &timer)
{
    visited[node] = true;
    low[node] = disc[node] = timer;
    timer++;

    int child = 0;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
        {
            continue;
        }

        if (!visited[neighbour])
        {
            dfs(adj, visited, low, disc, node, neighbour, atp, timer);

            // Upadte low
            low[node] = min(low[node], low[neighbour]);

            // Check Articulation Point or not
            if (low[neighbour] >= disc[node] && parent != -1)
            {
                // atp.push_back(node) this can lead to duplicaate entry in atp vector so dont uses it
                atp[node] = true;
            }

            child++;
        }

        else
        {
            // Back Edge case
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    // Check for first node if it have more than 1 child then it is a articulation point
    if (parent == -1 && child > 1)
    {
        atp[node] = true;
    }
}

vector<int> articulationPoint(vector<vector<int>> edges, int n)
{

    // Create Adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u); // Directed Graph
    }

    // Initialise Variable
    vector<bool> visited(n, false);
    vector<int> low(n, -1);
    vector<int> disc(n, -1);
    int parent = -1;
    int timer = 0;
    vector<int> atp(n, 0);

    // Chcking for all component of Graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, low, disc, parent, i, atp, timer);
        }
    }

    return atp;
}

int main()
{
    int n = 5, e = 5;
    vector<vector<int>> edges = {
        {0, 3},
        {0, 4},
        {0, 1},
        {1, 2},
        {3, 4}};

    vector<int> artiPoint = articulationPoint(edges, n);

    
    cout << "Articulation Points in the graph:\n";
    for (int i = 0; i < n; i++)
    {
        if (artiPoint[i] == 1)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
