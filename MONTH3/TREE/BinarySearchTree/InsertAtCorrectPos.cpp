#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
private:
    TreeNode *solve(TreeNode *root, int val)
    {
        TreeNode *parent = nullptr;
        TreeNode *current = root;

        while (current != nullptr)
        {
            parent = current; // last non-null node

            if (val < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return parent; // parent where new node should be attached
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);

        if (!root)
            return newNode;

        TreeNode *parent = solve(root, val);

        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        return root;
    }
};

// Helper function to print the tree in-order
void printInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Main function for testing
int main()
{
    Solution solution;

    // Create a sample BST: [4, 2, 7, 1, 3]
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    // Insert the value into the BST
    TreeNode *newRoot = solution.insertIntoBST(root, val);

    // Print the BST in-order to verify the insertion
    printInOrder(newRoot);

    return 0;
}
