#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class info
{
public:
    int maxi;
    int mini;
    int size;
    bool isBSt;
};

class Solution
{
private:
    info solve(TreeNode *root, int &ans)
    {
        if (!root)
            return {INT_MIN, INT_MAX, 0, true};

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info current;
        current.size = left.size + right.size + 1;
        current.maxi = max(root->data, right.maxi);
        current.mini = min(root->data, left.mini);

        if (right.isBSt && left.isBSt && (root->data > left.maxi) &&
            (root->data < right.mini))
        {
            current.isBSt = true;
        }
        else
        {
            current.isBSt = false;
        }

        if (current.isBSt)
        {
            ans = max(ans, current.size);
        }
        return current;
    }

public:
    int largestBST(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    Solution S;
    cout << "Size of largest BST in the tree: " << S.largestBST(root);

    return 0;
}
