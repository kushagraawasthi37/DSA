#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Create a map to store the parent of each node
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        // For parent tracking
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front->left) {
                q.push(front->left);
                parent[front->left] = front;
            }
            if (front->right) {
                q.push(front->right);
                parent[front->right] = front;
            }
        }

        // Step 2: Use BFS to find all nodes at distance k from the target
        vector<int> result;
        q.push(target);
        visited[target] = true;
        int currentDistance = 0;

        // Continue BFS until the desired distance is reached
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (currentDistance == k) {
                while (!q.empty()) {
                    result.push_back(q.front()->data);
                    q.pop();
                }
                return result;
            }

            int size = q.size();

            // Treaversing all the node at that distance/level
            for (int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();

                // Adding the left child of node to queue and visited
                if (front->left && visited[front->left] != true) {
                    visited[front->left] = true;
                    q.push(front->left);
                }
                // Adding the right child of node to queue and visited

                if (front->right && visited[front->right] != true) {
                    visited[front->right] = true;
                    q.push(front->right);
                }
                // Adding the parent of node to queue and visited

                if (parent[front] && visited[parent[front]] != true) {
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }
            }
            // All node at that  distance has traversed now increase the level
            currentDistance++;
        }

        return result;
    }
};
// Helper function to create a binary tree from a vector
TreeNode* createTree(const vector<int>& nodes, int index = 0) {
    if (index < nodes.size() && nodes[index] != -1) {
        TreeNode* root = new TreeNode(nodes[index]);
        root->left = createTree(nodes, 2 * index + 1);
        root->right = createTree(nodes, 2 * index + 2);
        return root;
    }
    return nullptr;
}

int main() {
    vector<int> nodes = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root = createTree(nodes);
    TreeNode* target = root->left;  // Node with value 5
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target node are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
