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

node *lowestCommonAnchestor(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    node *leftAns = lowestCommonAnchestor(root->left, n1, n2);
    node *rightAns = lowestCommonAnchestor(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
        return root;

    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;

    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;

    else
        return NULL;
}

int main()
{
    /*
             3
           /   \
          5     1
         / \   / \
        6   2 0   8
          / \
         7   4
    */

    node *root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->right->left = new node(0);
    root->right->right = new node(8);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);

    int n1 = 5, n2 = 1;
    node *lca = lowestCommonAnchestor(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found.\n";

    return 0;
}
