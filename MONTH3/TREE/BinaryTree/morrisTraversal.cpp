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

// Printing Inorder without extra space O(1)
void morrisInorderTraversal(node *root)
{
    // POSITIVE POINT
    // TC->O(N)
    // SC->O(1)

    node *current = root;

    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            // Find the inorder predecessor of current
            node *predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            // Make current the right child of its inorder predecessor
            // If the thread is not yet created
            if (predecessor->right == nullptr)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                // Revert the changes (restore tree structure)
                // Thread exists, break it
                predecessor->right = nullptr;
                cout << current->data << " "; // Inorder for preOrder this Line above the
                current = current->right;
            }
        }
    }
}

int main()
{ /*
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

    morrisInorderTraversal(root);

    return 0;
}