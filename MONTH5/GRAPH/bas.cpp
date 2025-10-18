#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
using namespace std;

/*
1.Graph data structure consists of node and edges

node-> that store some data
edge -> connection between the nodes

directed graph
undirected graph

weighted graph
Unweighted graph

path-> one node to another node traversal without repetition of any node
cyclic graph
weighted cyclic graph
weighted acyclic graph


Representation of graph

1.Adjacency Matrix(no of node,no of edge)
Implementation
2D Matrix : index represent nodes if node connected then 1 otherwsie 0

2.Adjacency List
node -> all nodes that are connected with it
N1->N2,N3
N2->N3

Implementation
map<int,list<int>> or vector<vector<int>>

*/

template <typename T>
class graph
{
public:
    /*Template<typename T> ki bhi automatic datatype le skta hai*/
    unordered_map<T /*Specific datatype bhi de skte ho*/, list<T /*Specific datatype bhi de skte ho*/>> adjList;
    // unordered_map<int,list<int>>

    vector<vector<int>> adjList1;

    void addEdge(int n1, int n2, bool direction)
    {
        // direction =0->Undirected Graph
        // direction =1-> Directed Graph

        // create a edge from
        adjList[n1].push_back(n2);

        // Undirected Graph
        if (direction == 0)
        {
            adjList[n2].push_back(n1);
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout < endl;
        }
    }

    vector<vector<int>> printAdjacencyList(int n, int e, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(n); // temp storage for adjacency better way

        // ans array will store all adjacent nodes corresonding on index
        for (int i = 0; i < e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            ans[u].push_back(v);
            // Undirected graph
            ans[v].push_back(u);
        }

        // Answer Printing
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            adj[i].push_back(i);

            // Entering neighbours
            for (int j = 0; j < ans[i].size(); j++)
            {
                adj[i].push_back(ans[i][j]);
            }
        }
        return adj;
    }
};

int main()
{
    int n;
    cout << "Enter the Number of nodes " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edge " << endl;
    cin >> m;

    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter 1 Node of Edge ";
        cin >> u;
        cout << "Enter 2 Node of Edge ";
        cin >> v;

        // Creating a undirected graph
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
}