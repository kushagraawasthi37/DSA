
class Solution {

private:
    int solve(vector<bool>& visited, vector<vector<int>>& adjList, int node,
              unordered_set<int>& s) {
        visited[node] = true;

        int ans = 1;

        for (auto nbr : adjList[node]) {
            if (!visited[nbr] && s.find(nbr) == s.end()) {
                ans += solve(visited, adjList, nbr, s);
            }
        }

        return ans;
    }

public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {

        unordered_set<int> s(restricted.begin(), restricted.end());
        if (s.find(0) != s.end())
            return 0;

        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int i = 0; i < adjList.size(); i++) {
            cout << i << "=>";
            for (int j : adjList[i])
                cout << j << " ";

            cout << endl;
        }

        vector<bool> visited(n,false);

        return solve(visited,adjList,0,s);
    }
};