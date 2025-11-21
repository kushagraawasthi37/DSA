#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Function to return the topological
     sorting of given graph */
    vector<int> topoSort(int V, vector<int> adj[])
    {

        // To store the In-degrees of nodes
        vector<int> inDegree(V, 0);

        // Update the in-degrees of nodes
        for (int i = 0; i < V; i++)
        {

            for (auto it : adj[i])
            {
                // Update the in-degree
                inDegree[it]++;
            }
        }

        // To store the result
        vector<int> ans;

        // Queue to facilitate BFS
        queue<int> q;

        // Add the nodes with no in-degree to queue
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Until the queue is empty
        while (!q.empty())
        {

            // Get the node
            int node = q.front();

            // Add it to the answer
            ans.push_back(node);
            q.pop();

            // Traverse the neighbours
            for (auto it : adj[node])
            {

                // Decrement the in-degree
                inDegree[it]--;

                /* Add the node to queue if
                its in-degree becomes zero */
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        // Return the result
        return ans;
    }

public:
    /* Function to determine if all
    the tasks can be finished */
    bool canFinish(int N, vector<vector<int>> arr)
    {

        // To store the graph
        vector<int> adj[N];

        // Form the graph
        for (auto it : arr)
        {
            int u = it[0];
            int v = it[1];

            // Add the edge v-> u
            adj[v].push_back(u);
        }

        // Get the topological ordering of graph
        vector<int> topo = topoSort(N, adj);

        /* If it doesn't contain
        all nodes, return false */
        if (topo.size() < N)
            return false;

        // Return true otherwise
        return true;
    }
};

int main()
{

    int N = 4;
    vector<vector<int>> arr = {
        {1, 0},
        {2, 1},
        {3, 2}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to determine if
    all the tasks can be finished */
    bool ans = sol.canFinish(N, arr);

    // Output
    if (ans)
        cout << "All the tasks can be finished.";
    else
        cout << "All the tasks can not be finished.";

    return 0;
}