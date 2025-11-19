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

void traverseLeft(node *root, vector<int> &ans)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, ans);

    else
        traverseLeft(root->right, ans);
}

void leafNode(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leafNode(root->left, ans);
    leafNode(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);

    else
        traverseRight(root->left, ans);

    // Bapas aagye
    ans.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return ans;
    }
    ans.push_back(root->data);

    // left part print
    traverseLeft(root->left, ans);

    // LeafNode  print
    leafNode(root, ans);

    // Right Part Print
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    /*
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
         /       \
        8         9
                   \
                   10
    */

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->right->left->right = new node(9);
    root->right->left->right->right = new node(10);

    vector<int> result = boundary(root);

    cout << "Boundary Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
