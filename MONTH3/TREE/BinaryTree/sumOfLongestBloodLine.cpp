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

void solve(node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (!root)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
            maxSum = max(maxSum, sum);

        return;
    }
    sum += root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongestbloodLine(node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = 0;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}
int main()
{
    return 0;
}