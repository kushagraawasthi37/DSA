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

node *solve(node *root, int &k, int n)
{

    if (root == NULL)
        return NULL;

    if (root->data == n)
        return root;

    node *leftAns = solve(root->left, k, n);
    node *rightAns = solve(root->right, k, n);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // Ans Lock kar diya
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // Ans lock kr diya
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(node *root)
{
    int k, n;
    node *ans = solve(root, k, n);
    if (ans == NULL || ans->data == n)
        return -1;

    else
        return ans->data;
}

int main()
{
    return 0;
}