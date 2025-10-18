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

void inOrder(node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

bool twoSumInBST(node *root, int target)
{
    if (!root)
        return false;

    vector<int> inorder;
    inOrder(root, inorder);

    // Inorder of BST gives Sorted Array

    int i = 0, j = inorder.size() - 1;

    while (i < j)
    {
        if (inorder[i] + inorder[j] == target)
            return true;

        if (inorder[i] + inorder[j] < target)
            i++;

        if (inorder[i] + inorder[j] > target)
            j--;
    }

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

    cout << "Sum 22 Exist or not :" << twoSumInBST(root, 22) << endl;
    cout << "Sum 99 Exist or not :" << twoSumInBST(root, 99) << endl;
    return 0;
}