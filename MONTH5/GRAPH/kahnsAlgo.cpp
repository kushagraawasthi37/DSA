#include <bits/stdc++.h>
using namespace std;

/*
step 01 find indegree of all node
step 02 create queue with 0 indegree element
step 03 do BFS and remove krte time indgree bhi kam karo uske neighbour ki
*/

vector<int> topologicalSortKahnsAlgo(vector<vector<int>> &edges, int n, int e)
{
    // create adj List
    vector<vector<int>> adj(n);
    // unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // Directed Graph
    }

    // Step 1: Find all Indegree
    vector<int> indegree(n);

    for (auto i : adj)
    {
        for (auto j : i)
        {
            indegree[j]++;
        }
    }

    /*
    Use Vector Instead of Map for more optimal
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    */

    // Step 2: 0 Indegree wale ko push kardo
    queue<int> q;

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    // step 3:do BFS
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store karlo
        ans.push_back(front);

     //   // neighbour Indegree update
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}


int main()
{
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};

    vector<int> ans = topologicalSortKahnsAlgo(edges, 6, 5);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}