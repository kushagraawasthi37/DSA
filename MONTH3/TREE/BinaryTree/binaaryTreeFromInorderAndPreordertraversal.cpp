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

int findPos(vector<int> inorder, int ele)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == ele)
        {
            return i;
        }
    }

    return -1;
}

void createMap(vector<int> inorder, map<int, int> &nodeToIndex)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        nodeToIndex[inorder[i]] = i;
    }
}

node *solve(vector<int> &inorder, vector<int> &preorder, int &preidx, int inorderSt, int inorderEnd, int n, map<int, int> nodeToIndex)
{
    if (preidx >= n || inorderSt > inorderEnd)
        return NULL;

    int ele = preorder[preidx++];
    node *root = new node(ele);

    int pos = findPos(inorder, ele);
    if (pos == -1)
    {
        return NULL;
    }

    // FOR CONSTANT TIME POSITION FIND USE Mapping
    int pos2 = nodeToIndex[ele];

    // First LeftSubtree
    root->left = solve(inorder, preorder, preidx, inorderSt, pos - 1, n, nodeToIndex);

    // Then Right SubTree
    root->right = solve(inorder, preorder, preidx, pos + 1, inorderEnd, n, nodeToIndex);

    return root;
}

node *buildTreeFromInordePreOrder(vector<int> &inorder, vector<int> &preorder, int n)
{
    int preIdx = 0;
    map<int, int> nodeToIndex;
    createMap(inorder, nodeToIndex);
    node *ans = solve(inorder, preorder, preIdx, 0, n - 1, n, nodeToIndex);
    return ans;
}

void levelOrder(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

int main()
{
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    node *root = buildTreeFromInordePreOrder(inorder, preorder, inorder.size());

    cout << "Level Order Traversal of Constructed Tree: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
