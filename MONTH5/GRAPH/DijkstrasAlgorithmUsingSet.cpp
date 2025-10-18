#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <limits.h>
#include <set>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int src)
{
    // Create adjacency List
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        pair<int, int> p1 = make_pair(v, wt);
        pair<int, int> p2 = make_pair(u, wt);

        adj[u].push_back(p1);
        adj[v].push_back(p2);
    }

    // Create distance Vector
    vector<int> distance(n, INT32_MAX);

    // We can use set or minheap for minimmum distance

    // Creation of set on basis (distance,node)
    set<pair<int /*Distance*/, int /*Node*/>> st;

    // Suppose source not not given
    // int src = 0;
    distance[src] = 0;

    st.insert(make_pair(0, src));

    while (!st.empty())
    {
        // fetch top record
        // Because set is always sorted by its elements, the first element (st.begin()) will always be the pair with:The smallest distance

        // auto top1 = st.begin();
        // int nDis=top1->first;
        // int no=top1->second;

        auto top = *(st.begin());

        int nodeDis = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        // Traverse on neighbour
        for (auto neighbour : adj[topNode])
        {

            if (nodeDis + neighbour.second < distance[neighbour.first])
            {
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

                // If record find erase it IN case of set but if using the priority queue then no need
                if (record != st.end())
                {
                    st.erase(record);
                }

                // Distance update
                distance[neighbour.first] = nodeDis + neighbour.second;

                // Record push in set
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }

    return distance;
}

int main()
{
    int n = 6;
    int edges = 7;
    vector<vector<int>> vec = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, 2},
        {1, 3, 1},
        {2, 3, 5},
        {3, 4, 3},
        {4, 5, 1}};

    int src = 0;
    vector<int> dist = dijkstra(vec, n, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}