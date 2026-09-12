

class BSTIterator {
private:
    stack<TreeNode*> s;

    void addLeftNode(TreeNode* root) {
        if (!root)
            return;

        s.push(root);
        if (root->left)
            addLeftNode(root->left);
    }

public:
    BSTIterator(TreeNode* root) { addLeftNode(root); }

    bool hasNext() { return !s.empty(); }

    int next() {
        TreeNode* node = s.top();
        s.pop();

        if (node->right)
            addLeftNode(node->right);

        return node->val;
    }
};