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

bool isBST(node *root, int mini, int maxi)
{
    if (!root)
        return true;

    if (root->data > mini && root->data < maxi)
    {
        bool left = isBST(root->left, mini, root->data);
        bool right = isBST(root->right, root->data, maxi);
        return left && right;
    }
    else
        return false;
}

int main()
{
    /*
         10
        /  \
       5    15
      / \     \
     2   7     20
    */

    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(2);
    root->left->right = new node(7);
    root->right->right = new node(20);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a BST." << endl;

    return 0;
}