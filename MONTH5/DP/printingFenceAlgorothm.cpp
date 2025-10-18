#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Not more than 2 adjancent Index have same entry

// (solve(n-2)*(k-1) ->Last 2 same
// +
// solve(n-1))*(k-1)-> Last 2 Different

// ways(n) = (k - 1) * (ways(n - 1) + ways(n - 2))
// This ensures no more than two adjacent posts are of the same color.

int printingFence(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    int ans = (k - 1) * (printingFence(n - 1, k) + printingFence(n - 2, k));
    return ans;
}

int solveMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    // Step 3:
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Step 2:
    dp[n] = (k - 1) * (solveMemo(n - 1, k, dp) + solveMemo(n - 2, k, dp));

    return dp[n];
}
int printingFenceMemo(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, k, dp);
}

int printingFenceTab(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    }

    return dp[n];
}
int printingFenceSpaceOpt(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    int prev2 = k;
    int prev1 = k * k;

    int curr;

    for (int i = 3; i <= n; i++)
    {
        curr = (k - 1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int main()
{
    vector<pair<int, int>> tests = {
        {1, 2}, {2, 2}, {3, 2}, {4, 3}, {5, 4}, {10, 2}};

    cout << "n\tk\trecursive\tmemo\t\ttab\t\tspaceOpt\n";
    for (int i = 0; i < tests.size(); i++)
    {
        int n = tests[i].first;
        int k = tests[i].second;

        cout << n << "\t" << k << "\t"
             << printingFence(n, k) << "\t\t"
             << printingFenceMemo(n, k) << "\t\t"
             << printingFenceTab(n, k) << "\t\t"
             << printingFenceSpaceOpt(n, k) << "\n";
    }

    return 0;
}