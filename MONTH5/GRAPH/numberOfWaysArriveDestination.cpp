#include <bits/stdc++.h>
using namespace std;


#define P pair<long long, int>
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int e = roads.size();

        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < e; i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        distance[0] = 0;
        ways[0] = 1;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            long long dis = top.first;

            for (auto ele : adj[node])
            {
                int tempDis = dis + ele.second;

                if (tempDis < distance[ele.first])
                {
                    distance[ele.first] = tempDis;
                    pq.push({tempDis, ele.first});
                    ways[ele.first] = ways[node];
                }
                else if (tempDis == distance[ele.first])
                {
                    // Abhi ke ele ke kitne ways hai
                    ways[ele.first] = (ways[ele.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
int main()
{
    int n = 7, m = 20;
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to get the number of ways to
    arrive at destinations in shortest possible time */
    int ans = sol.countPaths(n, roads);

    // Output
    cout << "The number of ways to arrive at destinations in shortest possible time is: " << ans;

    return 0;
}