#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
/*
Probelm :Dijjkstra Algorithm can not used in graph have negative weighted edge and give us wrong answer

The Bellman-Ford algorithm is used to find the shortest paths from a single source vertex to all other vertices in a weighted graph, even when some edge weights are negative.

✅ Key Features
Works for directed/undirected graphs

Handles negative weights

Can detect negative weight cycles


step 01: n-1 time har edge par jake d[u]+wt<d[v] wala formula lagao and then update kro

step 02: ek baar aur formula lagao agar koi update hau to iska matlab ki negative cycle present hai

*/

int shortestDistanceUsingBellmanFord(vector<vector<int>> &edges, int n, int src, int des)
{

    // Time: O(V * E)
    // Space: O(V)

    vector<int> distance(n, INT32_MAX);
    distance[src] = 0;

    for (int j = 0; j < n - 1; j++)
    {
        // For every Edge perform this n-1 time
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            // Update the distance if Smaller Path find
            if ((distance[u] != INT32_MAX) && (distance[u] + wt < distance[v]))
            {
                distance[v] = distance[u] + wt;
            }
        }
    }

    //// Final Checkup for cycle detection
    bool update = false;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        // Update the distance if Smaller Path find
        if ((distance[u] != INT32_MAX) && (distance[u] + wt < distance[v]))
        {
            update = true;
            distance[v] = distance[u] + wt;
        }
    }

    // No cycle detected
    if (!update)
        return distance[des];

    return -1;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    int src = 0, des = 3;
    int result = shortestDistanceUsingBellmanFord(edges, n, src, des);

    if (result == -1)
        cout << "No shortest path due to negative cycle.\n";
    else
        cout << "Shortest distance from " << src << " to " << des << " is: " << result << "\n";

    return 0;
}