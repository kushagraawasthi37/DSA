#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    int solve(TreeNode *root, int &maxi)
    {
        if (!root)
            return 0;

        // Suppose left se negative path aa rha hai use kyu hi add kare
        int left = max(0, solve(root->left, maxi));
        // Suppose right se negative path aa rha hai use kyu hi add kare
        int right = max(0, solve(root->right, maxi));

        // Update the maximum pathsum
        maxi = max(maxi, right + left + root->data);

        // Return the maximum path for upper nodes
        return root->data + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};
int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Finding and printing the maximum path sum
    int maxPathSum = solution.maxPathSum(root);
    std::cout << "Maximum Path Sum: " << maxPathSum << std::endl;

    return 0;
}
