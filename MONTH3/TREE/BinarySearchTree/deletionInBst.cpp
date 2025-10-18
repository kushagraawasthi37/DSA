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

node *findSucc(node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

node *deletion(node *root, int target)
{
    if (!root)
        return NULL;

    // Step 1 : Find target node
    if (target < root->data)
        root->left = deletion(root->left, target);

    else if (target > root->data)
        root->right = deletion(root->right, target);

    else
    {
        // Node found
        
        // Case 1: No child->leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if (!root->left)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else
        {
            node *succ = findSucc(root->right); // Inorder successor
            root->data = succ->data;
            // Succssor right mai hi hoga agar pred hota to left krte
            root->right = deletion(root->right, succ->data); // Delete successor
            /*Target Node ko uske Successor se replace kardo aab successor leaf node hai usko delete karo*/
        }
    }

    return root;
}

void inOrder(node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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

    cout << "Before Deletion: ";
    inOrder(root);
    cout << endl;

    root = deletion(root, 15); // important to update root

    cout << "After Deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
