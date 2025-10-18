
#include <bits/stdc++.h>
using namespace std;

// disjoint ->data structure 2 Important function
// 1.FindParent or findset
// 2.Union or UninonSet

// union by rank and path compression

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    // Last Node ka parent wahi node hoga uss node tak pahucho
    if (parent[node] == node)
    {
        return node;
    }

    // Without path compression
    //  return findParent(parent, parent[node]);

    // If want path Compression
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return;

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        // Make one parent of the other and increment *that* one's rank
        parent[v] = u; // u becomes root
        rank[u]++;
    }
}

/* If two node have same Parent then they belong from same component*/
int minSpannigTreeUsingKruskalAlgo(vector<vector<int>> &edges /*Weight 2nd index*/, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank);

    // Create a Linear data structure not Adjacency List

    // Sort on basis of Weight
    sort(edges.begin(), edges.end(), cmp);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        // If not part of same component then make its union
        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}
int main()
{
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    int result = minSpannigTreeUsingKruskalAlgo(edges, n);
    cout << "Minimum Spanning Tree weight: " << result << endl;

    return 0;
}
