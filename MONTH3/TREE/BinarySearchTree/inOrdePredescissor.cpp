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

pair<int, int> inOrderPredAndSuc(node *root, int key)
{
    int pre = -1;
    int suc = -1;
    node *temp = root;

    if (!root)
    {
        return make_pair(-1, -1);
    }

    // FIND KEY
    while (temp)
    {
        if (temp->data == key)
        {
            break;
        }
        else if (temp->data < key)
        {
            pre = temp->data; // potential predecessor iF Key is not in tree They become actual answer
            temp = temp->right;
        }
        else
        {
            suc = temp->data; // potential successor iF Key is not in tree They become actual answer
            temp = temp->left;
        }
    }

    // If key not found in BST
    if (!temp)
        return make_pair(pre, suc);

    // Check left subtree for actual predecessor
    node *inOrPre = temp->left;
    while (inOrPre)
    {
        pre = inOrPre->data;
        inOrPre = inOrPre->right;
    }

    // Check right subtree for actual successor
    node *inOrSuc = temp->right;
    while (inOrSuc)
    {
        suc = inOrSuc->data;
        inOrSuc = inOrSuc->left;
    }

    return make_pair(pre, suc);
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

    pair<int, int> p = inOrderPredAndSuc(root, 10);
    cout << "Inorder predecessor " << p.first << endl;
    cout << "Inorder successor " << p.second << endl;

    return 0;
}