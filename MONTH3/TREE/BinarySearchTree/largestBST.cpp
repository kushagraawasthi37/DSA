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

class info
{
public:
    int maxi;
    int mini;
    bool isBSt;
    int size;
};

info solve(node *root, int &ans)
{
    if (!root)
        return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info current;
    current.size = left.size + right.size + 1;
    current.maxi = max(root->data, right.maxi);
    current.mini = min(left.mini, root->data);

    if (right.isBSt && left.isBSt && (root->data > left.maxi) && (root->data < right.mini))
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

int largestBST(node *root)
{
    int ans = 0;
    solve(root, ans);
    return ans;
}

int main()
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(1);
    root->left->right = new node(8);
    root->right->right = new node(7);

    cout << "Size of largest BST in the tree: " << largestBST(root) << endl;

    return 0;
}
