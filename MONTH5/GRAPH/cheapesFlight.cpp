#include <bits/stdc++.h>
using namespace std;

/* Define P as a shorthand for
the pair<int, pair<int,int>> type */
#define P pair <int, pair<int,int>>

class Solution {
public:
    
    /* Function to find cheapest price from 
    src to dst with at most k stops */
    int CheapestFlight(int n, vector<vector<int>>& flights, 
                       int src, int dst, int k) {
        
        // To store the graph
        vector<pair<int,int>> adj[n];
        
        // Adding edges to the graph
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // To store minimum distance
        vector<int> minDist(n, 1e9);
        minDist[src] = 0;
        /* Queue storing the elements of 
        the form {stops, {node, dist}} */
        queue <P> q;
        
        // Add the source to the queue
        q.push({0, {src, 0}});
        
        // Until the queue is empty
        while(!q.empty()) {
            
            // Get the element from queue
            auto p = q.front(); q.pop();
            
            int stops = p.first; //stops
            int node = p.second.first; // node
            int dist = p.second.second; // distance
            
            /* If the number of stops taken exceed k,
            skip and move to the next element */
            if(stops > k) continue;
            
            // Traverse all the neighbors
            for(auto it : adj[node]) {
                
                int adjNode = it.first; // Adjacent node
                int edgeWt = it.second; // Edge weight
                
                /* If the tentative distance to 
                reach adjacent node is smaller 
                than the known distance and number 
                of stops doesn't exceed k */
                if(dist + edgeWt < minDist[adjNode] && 
                   stops <= k) {
                       
                    // Update the known distance
                    minDist[adjNode] = dist + edgeWt;
                    
                    // Add the new element to queue
                    q.push({stops+1, {adjNode, dist + edgeWt}});
                }
            }
        }
        
        /* If the destination is 
        unreachable, return -1 */
        if(minDist[dst] == 1e9) 
            return -1;
        
        // Otherwise return the result
        return minDist[dst];
    }
};

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };
    
    int src = 0, dst = 3, k = 1;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine cheapest flight 
    from source to destination within K stops */
    int ans = 
        sol.CheapestFlight(n, flights, src, dst, k);
    
    // Output
    cout << "The cheapest flight from source to destination within K stops is: " << ans;
    
    return 0;
}