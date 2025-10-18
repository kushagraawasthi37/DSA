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

node *solve(vector<int> &pre, int mini, int maxi, int &i)
{
    if (pre.size() == i)
        return NULL;

    if (pre[i] > maxi || pre[i] < mini)
        return NULL;

    node *root = new node(pre[i]);
    i++;

    root->left = solve(pre, mini, root->data, i);
    root->right = solve(pre, root->data, maxi, i);

    return root;
}
node *BSTFromPreOrder(node *root, vector<int> &pre)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(pre, mini, maxi, i);
}

void inOrderPrint(node *root)
{
    if (!root)
        return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    node *root = BSTFromPreOrder(NULL, preorder);

    cout << "Inorder traversal of the constructed BST: ";
    inOrderPrint(root);
    cout << endl;

    return 0;
}