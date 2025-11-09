#include <bits/stdc++.h>
using namespace std;

/*Graph with n node and n-1 edges and every node is reachable from another node->Spanning tree*/
// Spanning tree with minimum weight is called minimum spanning tree

vector<pair<pair<int, int>, int>> minimumSpanningTree(int n, vector<pair<pair<int /*u*/, int /*v*/>, int /*weight*/>> &edges, int src)
{

    // TC->O(n²)
    // SC->O(E + n)

    // Create adjacency List
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        // Node agar 1 se start hai agar 0 se start hai to u,v mai -1
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int wt = edges[i].second;

        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt)); // Undirected Graph
    }

    vector<int> updatedWeight(n, INT_MAX);
    vector<bool> minimumSpanningTreeNode(n, false);
    vector<int> parent(n, -1);

    // Start the algo
    updatedWeight[src] = 0;
    parent[src] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT32_MAX;
        int minimumNode = -1;

        // Find node with minimum value in updated Weight
        for (int j = 0; j < n; j++)
        {

            // Agar minimumSpanningTreeNode mai nhi hai
            if (minimumSpanningTreeNode[j] == false && updatedWeight[j] < mini)
            {
                minimumNode = j;
                mini = updatedWeight[minimumNode];
            }
        }

        // If all nodes are visited then
        if (minimumNode == -1)
        {
            break;
        }

        // Mark minimum node as true mean included in MinimumSpanning Tree
        minimumSpanningTreeNode[minimumNode] = true;

      //  // check its adjacent node
        for (auto neighbour : adj[minimumNode])
        {
            int v = neighbour.first;
            int wt = neighbour.second;

            if (minimumSpanningTreeNode[v] == false && wt < updatedWeight[v])
            {
                updatedWeight[v] = wt;
                parent[v] = minimumNode;
            }
        }
    }

    // creating answer
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 0; i < n; i++)
    {
        // pair<int, int> p = make_pair(parent[i], i);
        // pair<pair<int, int>, int> p1 = make_pair(p, updatedWeight[i]);
        // ans.push_back(p1);

        if (parent[i] != -1)
        {
            ans.push_back(make_pair(make_pair(parent[i], i), updatedWeight[i]));
        }
    }

    return ans;
}

int main()
{
    int n = 5;
    int src = 0;

    vector<pair<pair<int, int>, int>> edges = {
        {{0, 1}, 2},
        {{0, 3}, 6},
        {{1, 2}, 3},
        {{1, 3}, 8},
        {{1, 4}, 5},
        {{2, 4}, 7},
        {{3, 4}, 9}};

    auto mst = minimumSpanningTree(n, edges, src);

    cout << "Edges in Minimum Spanning Tree:\n";
    for (auto &edge : mst)
    {
        cout << edge.first.first << " - " << edge.first.second
             << " : weight = " << edge.second << "\n";
    }

    return 0;
}
