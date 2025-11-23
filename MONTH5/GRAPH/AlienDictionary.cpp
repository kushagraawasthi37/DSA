#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }

        return ans;
    }

public:
    string findOrder(string dict[], int N, int K) {

        // Adjacency list resizing
        vector<vector<int>> adj(K);

        for (int i = 0; i < N - 1; i++) {
            string w1 = dict[i];
            string w2 = dict[i + 1];

            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; j++) {

                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';
                    adj[u].push_back(v);
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";

        for (auto x : topo)
            ans.push_back(char(x + 'a'));

        return ans;
    }
};


int main() {
    
    int N = 5, K = 4;
    string dict[N] = {
        "baa","abcd","abca","cab","cad"
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine order of 
	letters based on alien dictionary */
    string ans =sol.findOrder(dict, N, K);
    
    // Output
    cout << "The order to characters as per alien dictionary is: " << ans;
    
    return 0;
}