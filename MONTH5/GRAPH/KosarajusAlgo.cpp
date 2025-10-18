#include <bits/stdc++.h>
using namespace std;
/*
Strongly connected Component ->wo component hote hai jisme kisi bhi node se start karo sab node tak pahuch jao
for Strongly Connected Component use use kosarajus algorithm

Kosaraju's Algorithm for Strongly Connected Components (SCC)
1. Do DFS and push nodes in stack according to finishing time (Topo sort)
2. Transpose the graph
3. Do DFS on transposed graph in stack order
*/

void dfs(unordered_map<int, list<int>> &adj, vector<int> &visited, int node, vector<int> &compo)
{

    visited[node] = true;
    compo.push_back(node);

    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfs(adj, visited, nbr, compo);
        }
    }
}
void dfsTopo(unordered_map<int, list<int>> &adj, vector<int> &visited, stack<int> &s, int node)
{

    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfsTopo(adj, visited, s, nbr);
        }
    }

    s.push(node);
}

vector<vector<int>> stronglyConnectedComponent(vector<vector<int>> &edges, int n)
{
    //TC->O(V+E)
    //SC->O()


    // Create Adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // Directed Graph
    }

    vector<int> visited(n, false);

    // Initiliase the Final variable
    int ssc = 0;
    vector<vector<int>> ans;

    // Step 1-> Do topological Sort
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTopo(adj, visited, s, i);
        }
    }

    // Step 2 ->Transpose of Graph (reverse the edges)
    for (int i = 0; i < edges.size(); i++)
    {
        swap(edges[i][0], edges[i][1]);
    }

    // New Adjacency List of Transpose graph
    unordered_map<int, list<int>> transAdj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        transAdj[u].push_back(v); // Directed Graph
    }

    // Again visited false for final answer

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Step 3->DFS call for final graph
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        vector<int> component;
        if (!visited[top])
        {
            dfs(transAdj, visited, top, component);
            ssc++;
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 2},
        {2, 1},
        {1, 0},
        {0, 3},
        {3, 4}};

    vector<vector<int>> sccs = stronglyConnectedComponent(edges, n);

    cout << "Strongly Connected Components:\n";
    for (auto &component : sccs)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
