#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<int> inCycle; // marks nodes that belong to ANY cycle

    bool dfs(int node, vector<int> adj[], vector<int> &visited,
             vector<int> &dfsVisited, vector<int> &check)
    {
        visited[node] = 1;
        dfsVisited[node] = 1;
        check[node] = 0;

        for (int nb : adj[node])
        {
            // go deeper if not visited
            if (!visited[nb])
            {
                if (dfs(nb, adj, visited, dfsVisited, check))
                    return true;
            }
            else if (dfsVisited[nb])
            {
                return true;
            }
        }
        check[node] = 1;
        dfsVisited[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> dfsVisited(V, 0);
        vector<int> check(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, dfsVisited, check);
            }
        }

        vector<int> res;
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                res.push_back(i);
        }

        return res;
    }
};

int main()
{

    int V = 7;
    vector<int> adj[V] = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to get the eventually
    safe nodes in the given graph */
    vector<int> ans = sol.eventualSafeNodes(V, adj);

    // Output
    cout << "The eventually safe nodes in the graph are:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}