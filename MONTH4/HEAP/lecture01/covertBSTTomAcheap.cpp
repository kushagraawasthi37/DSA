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

// Inorder ko store karo aur Uske postorder mai daal do Maxheap ban gaya

void inorder(node *root, vector<int> &in)
{
    if (!root)
        return;

    // Left jao
    inorder(root->left, in);
    // Inorder store karo
    in.push_back(root->data);
    // Right jao
    inorder(root->right, in);
}

void postOrderUse(node *root, vector<int> &in, int &idx)
{

    if (!root)
        return;

    // Left jao
    postOrderUse(root->left, in, idx);
    // Right jao
    postOrderUse(root->right, in, idx);
    // Data daal do
    root->data = in[idx];
    idx++;
}

// Step 3: Level-order traversal to verify result
void levelOrder(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        else
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
    }
}

// Helper: Insert into BST
node *insertBST(node *root, int val)
{
    if (!root)
        return new node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);

    else
        root->right = insertBST(root->right, val);

    return root;
}

int main()
{
    // Sample BST
    node *root = nullptr;
    root = insertBST(root, 8);
    root = insertBST(root, 3);
    root = insertBST(root, 10);
    root = insertBST(root, 1);
    root = insertBST(root, 6);
    root = insertBST(root, 14);
    root = insertBST(root, 4);
    root = insertBST(root, 7);
    root = insertBST(root, 13);

    vector<int> in;
    inorder(root, in);

    int idx = 0;
    postOrderUse(root, in, idx);

    cout << "Level order Of BST " << endl;
    levelOrder(root);

    cout << "Level order after converting BST to Max Heap:" << endl;
    levelOrder(root);

    return 0;
}