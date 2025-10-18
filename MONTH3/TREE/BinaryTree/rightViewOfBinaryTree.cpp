#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void RightViewSolve(node *root, vector<int> &ans, int level)
{

    if (!root)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    RightViewSolve(root->right, ans, level + 1);
    RightViewSolve(root->left, ans, level + 1);
}

vector<int> RightView(node *root)
{
    vector<int> ans;
    RightViewSolve(root, ans, 0);
    return ans;
}

int main()
{
    // Manually create the tree:
    /*
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
         / \
        8   9
             \
             10
    */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->left->right->right = new node(10);

    // Compute left view
    vector<int> view = RightView(root);

    // Print result
    cout << "right View: ";
    for (int val : view)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
