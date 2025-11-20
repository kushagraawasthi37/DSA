#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solveBFS(vector<vector<int>> &adj, vector<bool> &visited, int n,
                  int &cnt)
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
    int numProvinces(vector<vector<int>> edges)
    {
        vector<vector<int>> adj(edges.size(), vector<int>());
        for (int i = 0; i < edges.size(); i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {
                if (edges[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(adj.size(), false);
        int cnt = 0;
        for (int i = 0; i < adj.size(); i++)
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
    vector<vector<int>> adj =
        {
            {1, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {1, 0, 0, 1}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to find the
    provinces in the given graph */
    int ans = sol.numProvinces(adj);

    cout << "The number of provinces in the given graph is: " << ans;

    return 0;
}