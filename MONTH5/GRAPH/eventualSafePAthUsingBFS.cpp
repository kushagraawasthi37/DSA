#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    /* Function to return the topological
     sorting of given graph */
    vector<int> topoSort(int V, vector<int> adj[]) {
	    
        // To store the In-degrees of nodes
	    vector<int> inDegree(V, 0);
	    
	    // Update the in-degrees of nodes
		for (int i = 0; i < V; i++) {
		    
			for(auto it : adj[i]) {
			    // Update the in-degree
			    inDegree[it]++;
			}
		}

        
        // To store the result
        vector<int> ans;
	    
	    // Queue to facilitate BFS
	    queue<int> q;
	    
	    // Add the nodes with no in-degree to queue
	    for(int i=0; i<V; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }
	    
	    // Until the queue is empty
	    while(!q.empty()) {
	        
	        // Get the node
	        int node = q.front();
	        
	        // Add it to the answer
	        ans.push_back(node);
	        q.pop();
	        
	        // Traverse the neighbours
	        for(auto it : adj[node]) {
	            
	            // Decrement the in-degree
	            inDegree[it]--;
	            
	            /* Add the node to queue if 
	            its in-degree becomes zero */
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    
	    // Return the result
	    return ans;
    }
    
public:

	/* Function to get the
	eventually safe nodes */
	vector<int> eventualSafeNodes(int V, 
	                vector<int> adj[]) {
	    
	    // To store the reverse graph
	    vector<int> adjRev[V];
	    
	    // Reversing the edges
	    for (int i = 0; i < V; i++) {
		    
			// i -> it, it-> i
			for (auto it : adj[i]) {
			    
			    // Add the edge to reversed graph
				adjRev[it].push_back(i);
			}
		}
		
	    /* Return the topological 
	    sort of the given graph */
	    vector<int> result = topoSort(V, adjRev);
	    
	    // Sort the result
	    sort(result.begin(), result.end());
	    
	    // Return the result
	    return result;
	}
};

int main() {
    
    int V = 7;
    vector<int> adj[V] = {
         {1,2},
         {2,3},
         {5},
         {0},
         {5},
         {},
         {}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the eventually 
    safe nodes in the given graph */
    vector<int> ans = sol.eventualSafeNodes(V, adj);
    
    // Output
    cout << "The eventually safe nodes in the graph are:\n";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}