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

void solve(node *root, int k, int &count, vector<int> &path)
{
    if (!root)
        return;

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];

        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}

int kSumpath(node *root)
{
    vector<int> path;
    int count = 0;
    int k = 10;
    solve(root, k, count, path);
}

// Optimised Using the HashMap
void solveOptimized(node *root, int k, int currentSum, unordered_map<int, int> &prefixSumMap, int &count)
{
    if (root == NULL)
        return;

    // Update the current sum
    currentSum += root->data;

    // Check if there's a prefix path that sums to k
    if (prefixSumMap.find(currentSum - k) != prefixSumMap.end())
    {
        count += prefixSumMap[currentSum - k];
    }

    // Record the current prefix sum
    prefixSumMap[currentSum]++;

    // Reccurse
    solveOptimized(root->left, k, currentSum, prefixSumMap, count);
    solveOptimized(root->right, k, currentSum, prefixSumMap, count);

    // Backtrack
    prefixSumMap[currentSum]--;
}

int countKSumPaths(node *root, int k)
{
    unordered_map<int, int> prefixSumMap;
    prefixSumMap[0] = 1; // Important: to handle path equal to k from root
    int count = 0;
    solveOptimized(root, k, 0, prefixSumMap, count);
    return count;
}

int main()
{
    node *root = new node(1);
    root->left = new node(3);
    root->right = new node(-1);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->right->left->right = new node(1);
    root->right->right->right = new node(2);

    int k = 5;
    cout << "Total K-Sum Paths = " << countKSumPaths(root, k) << endl;

    return 0;
}