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

// MAPPING CREATE FOR CONSTANT TIME OPERATION
void createMap(vector<int> &in, map<int, int> &nodeToIndex)
{
    for (int i = 0; i < in.size(); i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

node *solve(vector<int> &inorder, vector<int> &postOrder, int &postIdx, int inorderSt, int inorderEnd, int n, map<int, int> nodeToIndex)
{
    if (postIdx < 0 || inorderSt > inorderEnd)
        return NULL;

    int ele = postOrder[postIdx];
    postIdx--;
    node *root = new node(ele);

    // FOR CONSTANT TIME POSITION FIND USE Mapping in inorder array
    int pos = nodeToIndex[ele];

    //First right subtree in postorder
    root->right = solve(inorder, postOrder, postIdx, pos + 1,  inorderEnd, n, nodeToIndex);

    //Then Only leftSubtree
    root->left = solve(inorder, postOrder, postIdx,  inorderSt, pos - 1, n, nodeToIndex);

    return root;
}

node *buildTreeFromInordePostOrder(vector<int> &inorder, vector<int> &postorder, int n)
{
    int postIdx = postorder.size() - 1;
    map<int, int> nodeToIndex;
    createMap(inorder, nodeToIndex);
    node *ans = solve(inorder, postorder, postIdx, 0, n - 1, n, nodeToIndex);
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
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    node *root = buildTreeFromInordePostOrder(inorder, postorder, 6);

    cout << "Level Order Traversal of Constructed Tree: ";
    levelOrder(root);
    cout << endl;

    return 0;
}