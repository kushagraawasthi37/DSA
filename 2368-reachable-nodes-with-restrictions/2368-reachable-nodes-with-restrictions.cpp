
class Solution {

private:
    int solve(int parent, vector<vector<int>>& adjList, int node,
              unordered_set<int>& s) {
        int ans = 1;

        for (auto nbr : adjList[node]) {
            if (parent !=nbr && s.find(nbr) == s.end()) {
                ans += solve(node, adjList, nbr, s);
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


    
        return solve(-1,adjList,0,s);
    }
};