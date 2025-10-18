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

node *createParentMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *res = NULL;
    queue<node *> q;
    
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->data == target)
            res = front;

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node *targetNode, map<node *, node *> nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;
    int ans = 0;

    q.push(targetNode);
    visited[targetNode] = true;

    while (!q.empty())
    {
        bool flag = false;
        
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // Process neighbouring node

            node *front = q.front();
            q.pop();

            // Left
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }

            // Right
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            // Parent
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }

        // Anything added in queue
        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(node *root, int target)
{
    // algo
    // step 1: create nodeToParent mapping
    // step 2: find target node
    // step 3: burn the tree in min time

    map<node *, node *> nodeToParent;
    node *targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main()
{
    /*
              1
             / \
            2   3
           / \   \
          4   5   6
             /
            7

        Let's assume target = 5
        Fire spreads in time units:
        Time 0: 5
        Time 1: 2, 7
        Time 2: 1, 4
        Time 3: 3
        Time 4: 6
        Answer: 4
    */

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->right->right = new node(6);

    int target = 5;

    cout << "Minimum time to burn the tree from node " << target << " is: " << minTime(root, target) << endl;

    return 0;
}
