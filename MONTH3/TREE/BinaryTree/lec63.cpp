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

int heightOfBinaryTree(node *root)
{
    // TC-> O(n)
    // SC-> O(height)

    if (root == NULL)
        return 0;

    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int widthDiaOftree(node *root)
{
    // TC->O(N^2)
    // SC->O(N)
    //  LONGEST PATH BETWEEN TWO ENDING NODE(ROOT/LEAF)-> DIAMETER OR WIDTH OF TREE

    if (root == NULL)
        return 0;

    int op1 = widthDiaOftree(root->left);                                           // Answer in left subtree
    int op2 = widthDiaOftree(root->right);                                          // answer in right subtree
    int op3 = heightOfBinaryTree(root->right) + heightOfBinaryTree(root->left) + 1; // Answer in both part

    int ans = max(op1, max(op2, op3));
    return ans;
}

pair<int, int> diameterFast(node *root)
{
    // TC->O(N)
    // SC->O(N)
    if (root == NULL)
    {
        pair<int /*Diameter*/, int /*Height*/> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = right.second + left.second + 1;

    pair<int, int> ans;
    // Diameter
    ans.first = max(op1, max(op2, op3)); // ✅ correct

    // Height
    ans.second = max(left.second, right.second) + 1;
}

bool isBalancedTree(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalancedTree(root->left);
    bool right = isBalancedTree(root->right);
    bool diff = abs(heightOfBinaryTree(root->left) - heightOfBinaryTree(root->right));

    return left && right && diff;
}

// A Sum Tree is a binary tree where for every non-leaf node, the node’s value = sum of its left subtree + right subtree.
pair<bool, int> sumTreeWithSum(node *root)
{
    // BASE CASE
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // LEAF NODE
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = sumTreeWithSum(root->left);  
    pair<bool, int> rightAns = sumTreeWithSum(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    bool condn = (root->data == leftAns.second + rightAns.second);

    pair<bool, int> ans;
    if (isLeftSumTree && isRightSumTree && condn)
    {
        ans.first = true;
        ans.second = root->data * 2;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}


int main()
{

    // HEIGHT OF BINARY TREE
    // DIAMETER  OF BINARY TREE
    // BALANCED TREE OR NOT
    // SUM OF TREE
    return 0;
}