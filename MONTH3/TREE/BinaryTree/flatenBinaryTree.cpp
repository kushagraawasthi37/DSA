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

void flattenBinaryTree(node *root)
{
    // Right skewed
    node *current = root;
    while (current)
    {
        if (current->left)
        {
            // Find predecizssior
            node *pred = current->left;
            while (pred->right)
            {
                pred = pred->right;
            }

            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
void flattenBinaryTreeLeft(node *root)
{
    // Left skewed
    node *current = root;
    while (current != NULL)
    {

        if (current->right)
        {
            // FIND SUCCESSSIOR
            node *successior = current->right;
            while (successior->left)
            {
                successior = successior->left;
            }

            successior->left = current->left;
            current->left = current->right;
            current->right = NULL;
        }
        current = current->left;
    }
}

void printFlattenedTree(node *root)
{
    cout << "Flattened Tree (Right Skewed): ";
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main()
{
    // Build tree manually:
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);

    flattenBinaryTree(root);

    printFlattenedTree(root);

    return 0;
}