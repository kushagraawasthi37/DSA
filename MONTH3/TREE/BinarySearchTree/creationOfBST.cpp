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

// using reccursion
node *insertBST(node *root, int val)
{

    // TC->O(logn)
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }

    // Add In left subtree
    if (val < root->data)
        root->left = insertBST(root->left, val);

    // Add in Right Subtree
    else
        root->right = insertBST(root->right, val);

    return root;
}

node *createBST()
{
    node *root = NULL;
    int val;
    cout << "Enter data for node " << endl;
    cin >> val;

    while (val != -1)
    {
        root = insertBST(root, val);
        cout << "Enter data for node " << endl;
        cin >> val;
    }

    return root;
}

// INORDER PREORDER AND LEVEL ORDER CODE SAME

void inOrder(node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

/*
INSERTION TC->O(N) WORST SKEW TREE CASE AND O(H)IN AVERAGE CASE H->HEIGHT N->NODE
SEARCH TC->O(N) WORST SKEW TREE CASE AND O(H)IN AVERAGE CASE H->HEIGHT N->NODE*/

int main()
{
    string input = "10 5 1 7 40 50 -1";
    stringstream ss(input);
    int val;
    node *root = NULL;

    while (ss >> val && val != -1)
    {
        root = insertBST(root, val);
    }

    cout << "Inorder Traversal (should be sorted): ";
    inOrder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
