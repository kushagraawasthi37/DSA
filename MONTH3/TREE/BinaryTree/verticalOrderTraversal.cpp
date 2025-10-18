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

vector<int> verticalOrder(node *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> m;
    queue<pair<node *, pair<int, int>>> q;// queue mai node aur uski horizontal,vertical distance store karenge

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        m[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    for (auto i : m)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main()
{
}