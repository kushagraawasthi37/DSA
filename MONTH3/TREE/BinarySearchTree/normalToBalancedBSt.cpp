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
    {
        return;
    }

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

node *solve(int s, int e, vector<int> inorder)
{

    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    node *root = new node(inorder[mid]);

    // Mid ke left ka alag tree ban do
    root->left = solve(s, mid - 1, inorder);
    // Mid ke right ke liye alag tree banao
    root->right = solve(mid + 1, e, inorder);

    return root;
}

node *balancedBST(node *root)
{
    vector<int> inorderVal;
    inOrder(root, inorderVal);
    return solve(0, inorderVal.size() - 1, inorderVal);
}

void printLevelOrder(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {

        node *front = q.front();
        q.pop();

        if (front != NULL)
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        else
        {
            // Level Complete
            cout << endl;

            if (!q.empty())
                q.push(NULL);
        }
    }
}

int main()
{
    // Create an unbalanced BST
    node *root = new node(1);
    root->right = new node(2);
    root->right->right = new node(3);
    root->right->right->right = new node(4);
    root->right->right->right->right = new node(5);

    cout << "Before balancing (level order): " << endl;
    printLevelOrder(root);

    node *balanced = balancedBST(root);

    cout << "\nAfter balancing (level order): \n";
    printLevelOrder(balanced);

    return 0;
}
