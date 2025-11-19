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
        return NULL;

    cout << "Left child of node " << val << endl;
    root->left = buildTree(root->left);

    cout << "right child of node " << val << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front == NULL /*PUARANA LEVEL COMPLETE HOGYA HAI */)
        {
            cout << endl;
            if (!q.empty())
            {
                // Queue still have some child node
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
    }
}

void reverseLevelOrderTraversal(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    stack<node *> s;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        // Note: Push right child first so left child comes out of stack first
        if (temp->right)
            q.push(temp->right);

        if (temp->left)
            q.push(temp->left);
    }

    // Print contents of the stack (reverse level order)
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

void inOrderTraversal(node *root)
{
    if (!root)
        return;

    // LEFT CHILD
    inOrderTraversal(root->left);

    // DATA
    cout << root->data << " ";

    // RIGHT CHILD
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root)
{
    if (!root)
        return;

    // ROOT DATA
    cout << root->data << " ";

    // LEFT CHILD
    preOrderTraversal(root->left);

    // RIGHT CHILD
    preOrderTraversal(root->right);
}

void postOrderTraversal(node *root)
{
    if (!root)
        return;

    // LEFT CHILD
    postOrderTraversal(root->left);

    // RIGHT CHILD
    postOrderTraversal(root->right);
    //ROOT DATA
    cout << root->data << " ";
}

void *buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root ";
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // Left child
        cout << "Enter Left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        // Right child
        cout << "Enter Right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void noOfLeafNode(node *root, int &count)
{

    if (root->right == NULL && root->left == NULL)
    {
        count++;
    }
    if (root->left == NULL || root->right == NULL)
    {
        return;
    }
    noOfLeafNode(root->left, count);
    noOfLeafNode(root->right, count);
}
int main()
{
    // TREE ARE NON LINEAR DATA STRUCTURE
    // EK NODE MULTIPLE NODE SE CONNECT HO SKTA HAI
    // BINARY TREE HAR NODE KE MAXIMUM 2 NODE HO SKTE HAI

    // CREATION OF BINARY TREE
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildTree(root);

    // LEVEL ORDER TRAVERSAL
    cout << endl;
    levelOrderTraversal(root);

    // REVRESE LEVEL ORDER TRAVERSAL
    cout << endl;
    reverseLevelOrderTraversal(root);

    // INORDER TRAVERSAL
    cout << endl;
    inOrderTraversal(root);

    // PREORDER TRAVERSAL
    cout << endl;
    preOrderTraversal(root);

    // POSTORDER TRAVERSAL
    cout << endl;
    postOrderTraversal(root);

    // BUILD FROM LEVEL ORDER TRAVERSAL
    buildFromLevelOrder(root);

    // CALCULATE THE NUMBER OF LEAF NODE IN TREE
    int count = 0;
    noOfLeafNode(root, count);
    cout << count << endl;

    return 0;
}