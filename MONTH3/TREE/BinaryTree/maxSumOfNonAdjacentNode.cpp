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

pair<int, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<int /*Sum Including*/, int /*Sum excluding*/> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;
    // Max Sum including the all node at current level
    res.first = root->data + left.second + right.second;

    // Max Sum excluding the all node at current level
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}
int maxSumOfNonAdjacentNode(node *root)
{

    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    /*
           10
          /  \
         1    2
        / \    \
       3   4    5
    */

    node *root = new node(10);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(5);

    cout << "Maximum sum of non-adjacent nodes: " << maxSumOfNonAdjacentNode(root) << endl;

    return 0;
}
