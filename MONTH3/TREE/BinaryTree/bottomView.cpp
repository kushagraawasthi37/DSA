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

vector<int> bottomView(node *root)
{
    vector<int> ans;

    if (!root)
        return ans;
        
    map<int, int> m;
    queue<pair<node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        m[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    // Build tree manually
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(5);

    vector<int> result = bottomView(root);
    cout << "Bottom View: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
