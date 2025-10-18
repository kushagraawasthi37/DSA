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
        left = right = nullptr;
    }
};

// Hypothesis
int heightOfTree(node *root)
{
    // Base condition
    if (!root)
    {
        return 0;
    }

    // Hypothesis for smaller input
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    // Induction
    return 1 + max(left, right);
}

int main()
{
    return 0;
}