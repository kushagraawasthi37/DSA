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

int solve(node *root, int &i, int k)
{
    // Inorder Traversal hi krna hai lekin first i node ka ith node hi smallest ith node hai
    if (!root)
    {
        return -1;
    }

    // Left Case
    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // Node case
    i++;

    if (i == k)
        return root->data;

    // Right Case
    return solve(root->right, i, k);
}

int kthSmallestElement(node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int solveMor(node *root, int &i, int k)
{
    node *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            i++;
            if (i == k)
            {
                return current->data;
            }
            current = current->right;
        }
        else
        {
            node *predecessor = current->left;

            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                i++;
                if (i == k)
                {
                    return current->data;
                }
                current = current->right;
            }
        }
    }
    return -1; // If k is too large
}

int ktSmallestUsingMorris(node *root, int k)
{
    int i = 0;
    return solveMor(root, i, k);
}

// DO THIS USING MORRIS TRAVERSAL HOMEWORK

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

    cout << "5th Smallest Element Using simple Inorder :" << kthSmallestElement(root, 5) << endl;
    cout << "5th Smallest Element using Morris :" << ktSmallestUsingMorris(root, 5) << endl;

    return 0;
}