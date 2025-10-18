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

bool searchInBST(node *root, int target)
{
    if (root == NULL)
        return false;

    while (root != NULL)
    {
        // target Found
        if (root->data == target)
            return true;

        // Search in right subtree
        if (root->data < target)
            root = root->right;

        // Search in left subtree
        if (root->data > target)
            root = root->left;
    }

    return false;
}

int main()
{
    /*
     10
    /  \
   5    25
  / \     \
 2   7     20
*/
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(25);
    root->left->left = new node(2);
    root->left->right = new node(7);
    root->right->right = new node(20);

    cout << "Search 15 :" << searchInBST(root, 15) << endl;
    cout << "Search 2 :" << searchInBST(root, 2) << endl;
    return 0;
}