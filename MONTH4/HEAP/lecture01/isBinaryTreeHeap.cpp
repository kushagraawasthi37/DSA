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

int countNode(node *root)
{
    if (root == NULL)
        return 0;

    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}

bool isCBT(node *root, int i, int nodeCount)
{
    if (!root)
        return true;

    if (i >= nodeCount)
        return false;

    bool left = isCBT(root->left, 2 * i + 1, nodeCount);
    bool right = isCBT(root->right, 2 * i + 2, nodeCount);

    return (left && right);
}

bool isMaxOrder(node *root)
{

    if (!root)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true; 

    if (root->right == NULL)
    {
        if (root->data >= root->left->data)
            return true;

        return false;
    }
    // Only Right child condition does not passed because it in Complete binary tree node have single child then it must be Left child

    // Both child exist
    if ((root->data >= root->left->data) && (root->data >= root->right->data) && isMaxOrder(root->left) && isMaxOrder(root->right))
        return true;

    return false;
}

bool isBinaryTreeHeap(node *root)
{
    // TC->O(n)
    // SC->O(h)
    int index = 0;
    int totalNodeCount = countNode(root);
    if (isCBT(root, index, totalNodeCount) && isMaxOrder(root))
        return true;

    return false;
}
int main()
{
    /*
        Constructing the following binary tree:

                10
               /  \
              9    8
             / \  /
            7  6 5

        This is a complete binary tree and also follows max-heap property
    */

    node *root = new node(10);
    root->left = new node(9);
    root->right = new node(8);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);

    if (isBinaryTreeHeap(root))
        cout << "Yes, the binary tree is a max-heap.\n";
    else
        cout << "No, the binary tree is NOT a max-heap.\n";

    return 0;
}
