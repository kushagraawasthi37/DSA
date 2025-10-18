#include <iostream>
#include <vector>
using namespace std;

int solveRecc(vector<int> &arr, int idx)
{
    if (idx >= arr.size())
        return 0;

    // Include
    int incl = solveRecc(arr, idx + 2) + arr[idx];
    // exclude
    int excl = solveRecc(arr, idx + 1);

    return max(excl, incl);
}

int maxSumOfNonAdjacentEleRecc(vector<int> &arr)
{
    // TC->	O(2^n)
    // SC->	O(n) (stack depth)

    int n = arr.size();
    int ans = solveRecc(arr, 0);
    return ans;
}

int solveDpMem(vector<int> &arr, int idx, vector<int> &dp)
{
    // Base case:
    if (idx >= arr.size())
        return 0;

    // Step 3:Check DP
    if (dp[idx] != -1)
        return dp[idx];

    // Include
    int incl = solveDpMem(arr, idx + 2, dp) + arr[idx];
    // exclude
    int excl = solveDpMem(arr, idx + 1, dp);

    // Step 2:Update DP
    dp[idx] = max(excl, incl);

    return dp[idx];
}
int maxSumOfNonAdjacentEleDpMem(vector<int> &arr)
{
    // TC->	O(n)
    // SC->	O(n) (dp + stack)

    int n = arr.size();
    //Step 1:Create DP
    vector<int> dp(n + 1, -1);

    int ans = solveDpMem(arr, 0, dp);
    return ans;
}

int maxSumOfNonAdjacentEleDpTab(vector<int> &arr)
{
    // TC->	O(n)
    // SC->	O(n) (dp)

    int n = arr.size();
    // Edge Case
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    // Step 1:
    vector<int> dp(n + 1, -1);

    // Base case:
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        // Include
        int incl = dp[i - 2] + arr[i];
        // Exclude
        int excl = dp[i - 1];

        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}

int maxSumOfNonAdjacentEleDpSp(vector<int> &arr)
{
    // TC->	O(n)
    // SC->	O(1)

    int n = arr.size();
    // Edge Case
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    // Step 1:
    int prevMax2 = arr[0];
    int prevMax1 = max(arr[0], arr[1]);

    int curr;
    for (int i = 2; i < n; i++)
    {
        // Include
        int incl = prevMax2 + arr[i];
        // Exclude
        int excl = prevMax1;

        curr = max(incl, excl);
        prevMax2 = prevMax1;
        prevMax1 = curr;
    }
    return max(prevMax1, prevMax2);
}

int main()
{
    vector<int> arr = {9, 9, 8, 2};

    cout << "Recursion: " << maxSumOfNonAdjacentEleRecc(arr) << endl;
    cout << "DP with Memoization: " << maxSumOfNonAdjacentEleDpMem(arr) << endl;
    cout << "DP with Tabulation: " << maxSumOfNonAdjacentEleDpTab(arr) << endl;
    cout << "Space Optimized DP: " << maxSumOfNonAdjacentEleDpSp(arr) << endl;

    return 0;
}
