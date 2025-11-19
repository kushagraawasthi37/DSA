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
    int widthOfBinaryTree(TreeNode *root)
    {
        // your code goes here
        int ans = 0;
        if (!root)
            return ans;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto front = q.front();
            int size = q.size();

            int mmin = front.second;
            int left = 0;
            int right = 0;

            for (int i = 0; i < size; i++)
            {
                int cur_id = q.front().second - mmin;
                TreeNode *front = q.front().first;
                // Pop the front node from the queue
                q.pop();
                if (i == 0)
                    left = cur_id;
                if (i == size - 1)
                    right = cur_id;

                if (front->left)
                {
                    q.push({front->left, 2 * cur_id + 1});
                }
                if (front->right)
                {
                    q.push({front->right, 2 * cur_id + 2});
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: " << maxWidth << endl;

    return 0;
}
