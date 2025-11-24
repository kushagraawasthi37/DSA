#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solveBFS(vector<int> adj[], vector<int> &color, int node)
    {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();
            for (auto ele : adj[frontNode])
            {
                if (color[ele] == -1)
                {
                    color[ele] = !color[frontNode];
                    q.push(ele);
                }
                else if (color[ele] == color[frontNode])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!solveBFS(adj, color, i))
                    return false;
            }
        }

        return true;
    }
};

int main()
{

    int V = 4;
    vector<int> adj[V] = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to check
    if the given graph is bipartite */
    bool ans = sol.isBipartite(V, adj);

    // Output
    if (ans)
        cout << "The given graph is a bipartite graph.";
    else
        cout << "The given graph is not a bipartite graph.";

    return 0;
}