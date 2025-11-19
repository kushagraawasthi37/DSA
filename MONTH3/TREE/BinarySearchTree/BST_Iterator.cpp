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

// Class for BST Iterator
class BSTIterator
{
private:
    void getInOrder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        getInOrder(root->left, inorder);
        inorder.push_back(root->data);
        getInOrder(root->right, inorder);
    }

public:
    vector<int> inorder;
    int cnt = 0;
    BSTIterator(TreeNode *root) { getInOrder(root, inorder); }

    bool hasNext()
    {
        return cnt < inorder.size();
    }

    int next()
    {
        return inorder[cnt++];
    }
};

// Main method to demonstrate the usage of BSTIterator
int main()
{
    // Create a sample binary search tree
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Instantiate the BSTIterator with the root of the tree
    BSTIterator *iterator = new BSTIterator(root);

    // Use the iterator to get the elements in sorted order
    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }

    // Output: 3 7 9 15 20

    return 0;
}
