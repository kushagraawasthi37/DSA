/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode*> s;
    bool reverse = false;

    void addNode(TreeNode* node) {
        while (node) {
            s.push(node);
            node = (reverse) ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        addNode(root);
    }

    bool hasNext() { return !s.empty(); }

    int next() {
        TreeNode* node = s.top();
        s.pop();

        TreeNode* curr = reverse ? node->left : node->right;

        addNode(curr);

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* org = new BSTIterator(root, false);
        BSTIterator* rev = new BSTIterator(root, true);

        int i = org->next();
        int j = rev->next();

        while (i < j) {
            if (i + j == k)
                return true;

            if (i + j < k) {
                i = org->next();
            } else
                j = rev->next();
        }
        return false;
    }
};