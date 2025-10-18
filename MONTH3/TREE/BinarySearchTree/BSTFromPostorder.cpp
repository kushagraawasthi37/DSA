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
node *solve(vector<int> &post, int mini, int maxi, int &i)
{
    if (post.size() == i)
        return NULL;

    if (post[i] > maxi || post[i] < mini)
        return NULL;

    node *root = new node(post[i]);
    i--;

    root->right = solve(post, root->data, maxi, i);
    root->left = solve(post, mini, root->data, i);

    return root;
}
node *BSTFromPreOrder(node *root, vector<int> &post)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = post.size()-1;;
    return solve(post, mini, maxi, i);
}

int main()
{
    return 0;
}