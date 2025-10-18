#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[v].push_back(u);
        adjList[u].push_back(v); // Undirected Graph
    }
}

// Set use instead of map it give in sorted answer
void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store front node to answer
        ans.push_back(frontNode);

        // traverse all neighbour of front node

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                // pushing neighbour in queue
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFStraversal(int vertex, vector<pair<int, int>> edges)
{

    // node then uske sab adjacent print kardo
    unordered_map<int, list<int>> adjList;
    // return ans
    vector<int> ans;

    // To check weather the node is visited or not
    unordered_map<int, bool> visited;

    // Step 1 : Create a Adjacent List
    prepareAdjList(adjList, edges);

    // Traverses all component of graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}
int main()
{
    int vertex = 6;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};

    vector<int> bfsResult = BFStraversal(vertex, edges);

    cout << "BFS Traversal: ";
    for (int node : bfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
