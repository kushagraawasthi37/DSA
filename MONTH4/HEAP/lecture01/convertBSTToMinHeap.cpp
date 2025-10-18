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

//Inorder ko store karo aur Uske preorder mai daal do min heap ban gaya
void inOrderTraversal(node *root, vector<int> &in)
{
    if (!root)
        return;

    // LEFT CHILD
    inOrderTraversal(root->left, in);
    in.push_back(root->data);

    // RIGHT CHILD
    inOrderTraversal(root->right, in);
}

void fillPreOrder(node *root, vector<int> &in, int &idx)
{
    if (!root)
    {
        return;
    }

    root->data = in[idx];
    idx++;

    fillPreOrder(root->left, in, idx);
    fillPreOrder(root->right, in, idx);
}

int main()
{
    return 0;
}