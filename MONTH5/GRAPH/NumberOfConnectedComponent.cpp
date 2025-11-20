#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solveBFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited,
                  int n, int &cnt)
    {
        cnt++;
        queue<int> q;
        q.push(n);
        visited[n] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto ele : adj[frontNode])
            {
                if (!visited[ele])
                {
                    visited[ele] = true;
                    q.push(ele);
                }
            }
        }
    }

public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(V, false);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                solveBFS(adj, visited, i, cnt);
            }
        }

        return cnt;
    }
};
int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to find the number of
    connected components in the given graph */
    int ans = sol.findNumberOfComponent(V, edges);

    cout << "The number of components in the given graph is: " << ans;

    return 0;
}