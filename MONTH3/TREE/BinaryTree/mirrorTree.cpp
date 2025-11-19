#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true; // An empty tree is symmetric
        }
        return symmetry(root->left, root->right);
    }

private:
    bool symmetry(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true; // Both nodes are null, so symmetric
        }

        if (left == nullptr || right == nullptr)
        {
            return false; // One of the nodes is null, so not symmetric
        }

        if (left->data != right->data)
        {
            return false; // The values of the nodes do not match, so not symmetric
        }

        // Recursively check the children of the nodes
        return symmetry(left->left, right->right) && symmetry(left->right, right->left);
    }
};

// Example usage
int main()
{
    Solution solution;

    // Create a sample tree: 1, 2, 2, 3, 4, 4, 3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Test the symmetric tree
    Solution S;
    cout << S.isSymmetric(root);
    return 0;
}
