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

void inOrder(node *root, vector<node *> &in)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, in);
    in.push_back(root);
    inOrder(root->right, in);
}

node *flatenBSTRightSkew(node *root)
{

    // Create Inorder vector
    vector<node *> in;
    inOrder(root, in);

    // Step1 : First node
    // root = in[0];// this isn't technically wrong, but it's bad practice.
    node *newroot = in[0];
    node *curr = newroot;

    // 2nd step
    for (int i = 1; i < in.size(); i++)
    {
        // Create new node
        node *temp = in[i];
        // ReLinking
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd Step: Last Node
    curr->left = NULL;
    curr->right = NULL;

    return newroot;
}

node *flatenBSTLeftSkew(node *root)
{

    // Create Inorder vector
    vector<node *> in;
    inOrder(root, in);

    // Step1 : First node
    // root = in[0];// this isn't technically wrong, but it's bad practice.
    node *newroot = in[0];
    node *curr = newroot;

    // 2nd step
    for (int i = 1; i < in.size(); i++)
    {
        // Create new node
        node *temp = in[i];
        // ReLinking
        curr->left = temp;
        curr->right = nullptr;
        curr = temp;
    }

    // 3rd Step: Last Node
    curr->left = NULL;
    curr->right = NULL;

    return newroot;
}

void printRightSkewed(node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main()
{
    // Construct BST
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);

    // Flatten BST
    node *newRoot = flatenBSTRightSkew(root);

    // Print right-skewed tree
    printRightSkewed(newRoot);

    return 0;
}
