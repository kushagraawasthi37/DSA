#include <iostream>
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

node *buildTree(node *root)
{
    int val;
    cout << "Enter the data ";
    cin >> val;

    root = new node(val);

    if (val == -1)
    {
        return NULL;
    }

    cout << "Left child of node " << val << endl;
    root->left = buildTree(root->left);

    cout << "right child of node " << val << endl;
    root->right = buildTree(root->right);

    return root;
}

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);

    bool leftToRight = false;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // LEVEL-WISE PROCESS

        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();

            int index;

            if (leftToRight == true)
                index = i;
            else
                index = size - i - 1;

            ans[index] = frontnode->data;

            if (frontnode->left)
                q.push(frontnode->left);

            if (frontnode->right)
                q.push(frontnode->right);
        }

        // REVERSE THE DIRECTION
        leftToRight = !leftToRight;

        for (auto i : ans)
            result.push_back(i);
    }
    return result;
}

int main()
{

    // Manually building this tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    vector<int> result = zigZagTraversal(root);

    cout << "\nZigzag Level Order Traversal: ";
    for (int val : result)
        cout << val << " ";

    cout << endl;
    return 0;
}