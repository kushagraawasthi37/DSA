#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> minimumSpanningTree(int n, vector<pair<pair<int /*u*/, int /*v*/>, int /*weight*/>> &edges, int src)
{
    // Time Complexity: O((V + E) * log V)
    // Space Complexity: O(V + E)

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

    // Min heap ->
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);  // store min weight to reach each node
    vector<bool> inMST(n, false); // to mark if node is included in MST

    key[src] = 0;
    pq.push(make_pair(0, src)); // weight = 0, node = src

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Node already Visited then Move ahead
        if (inMST[u] == true)
            continue;

        // Update the node if not visited
        inMST[u] = true;

        //
        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int wt = neighbour.second;

            if (inMST[v] == false && wt < key[v])
            {
                key[v] = wt;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    // Prepare MST result
    vector<pair<pair<int, int>, int>> result;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            result.push_back(make_pair(make_pair(parent[i], i), key[i]));
        }
    }

    return result;
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

    vector<pair<pair<int, int>, int>> mst = minimumSpanningTree(n, edges, src);

    int totalWeight = 0;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].first.first << " - " << mst[i].first.second << " : " << mst[i].second << endl;
        totalWeight += mst[i].second;
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
