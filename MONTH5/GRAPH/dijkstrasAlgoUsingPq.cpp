#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Dijkstra's Algorithm Using Priority Queue
/*Feature	                       set	                                  priority_queue
Duplicate entries	  |   Removed manually (by erase)	|           Allowed, old entries ignored
Decrease key	      |   Manual via erase + insert	    |           No direct way; push new value
Performance	O(log N)  |   insert/erase	                |           Faster O(log N) without erase
Simpler to implement  | ❌ No — need erase	           |     ✅ Yes — just push when updated*/

vector<int> dijkstra(int n, vector<vector<int>> &edges, int src)
{

    // Step 1: Create adjacency list
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Remove this line for directed graph
    }

    // Step 2: Distance array
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    // Step 3: Min-heap using priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

    minheap.push({0, src}); // {distance, node}

    while (!minheap.empty())
    {

        // Node with minimum Distance
        auto top = minheap.top();
        minheap.pop();

        int nodeDistance = top.first;
        int node = top.second;

        // Traverse all neighbours of current node
        for (auto neighbour : adj[node])
        {
            if (neighbour.second + nodeDistance < distance[neighbour.first])
            {
                distance[neighbour.first] = neighbour.second + nodeDistance;
                minheap.push({distance[neighbour.first], neighbour.first});
            }
        }
    }

    return distance;
}

int main()
{
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}};
    int src = 0;

    vector<int> dist = dijkstra(n, edges, src);

    // Output distances
    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < dist.size(); ++i)
    {
        cout << "To node " << i << " = " << dist[i] << '\n';
    }

    return 0;
}
