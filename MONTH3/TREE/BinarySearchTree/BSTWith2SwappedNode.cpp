#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    void getInOrder(vector<int> &inorder, TreeNode *root)
    {
        if (!root)
            return;

        getInOrder(inorder, root->left);
        inorder.push_back(root->data);
        getInOrder(inorder, root->right);
    }

    void updateFromInorder(TreeNode *root, vector<int> &inorder, int &idx)
    {
        if (!root)
            return;

        updateFromInorder(root->left, inorder, idx);
        root->data = inorder[idx++];
        updateFromInorder(root->right, inorder, idx);
    }

    void recoverTree(TreeNode *root)
    {
        vector<int> inorder;
        getInOrder(inorder, root);
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        updateFromInorder(root, inorder, idx);
    }
};
// Helper function to insert nodes in the tree for testing purposes
TreeNode *insertLevelOrder(vector<int> &arr, int i)
{
    if (i >= arr.size() || arr[i] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    return root;
}

// Helper function to print inorder traversal of the tree
void inorderPrint(TreeNode *root)
{
    if (root)
    {
        inorderPrint(root->left);
        cout << root->data << " ";
        inorderPrint(root->right);
    }
}

int main()
{
    // Example input tree: [1, 3, -1, -1, 2]
    vector<int> nodes = {3, 1, 4, -1, -1, 2, -1};
    TreeNode *root = insertLevelOrder(nodes, 0);
    cout << "Before ";
    inorderPrint(root);

    // Solution instance
    Solution sol;
    sol.recoverTree(root);

    // Print corrected tree
    cout << "\n After ";
    inorderPrint(root);

    return 0;
}
