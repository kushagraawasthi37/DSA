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

node *LCAOfBST(node *root, node *r1, node *r2)
{
    if (!root)
        return NULL;

    // Both node In RightSubtree
    if (root->data < r1->data && root->data < r2->data)
        return LCAOfBST(root->right, r1, r2);

    // Both Node are in LeftSubtree
    else if (root->data > r1->data && root->data > r2->data)
        return LCAOfBST(root->left, r1, r2);

    // One Node Left Subtree and Other in Right Subtree
    else
        return root;
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

    node *LCA = LCAOfBST(root, root->right->right, root->left->right);
    cout << "Least Common Ancestor of 20 and 7 is : " << LCA->data << endl;
    return 0;
}