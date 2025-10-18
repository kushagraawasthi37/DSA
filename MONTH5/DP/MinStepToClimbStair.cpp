#include <iostream>
#include <vector>
using namespace std;

int maxDistinctWaysToClimbStair(int nStair, int i)
{
    // It Cause TLE(Time Limit Exceeds) Using reccursion
    if (i == nStair)
        return 1;

    if (i > nStair)
        return 0;

    return maxDistinctWaysToClimbStair(nStair, i + 1) + maxDistinctWaysToClimbStair(nStair, i + 2);
}

int solve(vector<int> &cost, int n)
{
    // base case
    if (n == 0 || n == 1)
        return cost[n];

    int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    return ans;
}

int minCostToClimbStairRecc(vector<int> &cost)
{
    // It Cause TLE(Time Limit Exceeds) Using reccursion Add memorisation in it

    int n = cost.size();
    // It can be simplified
    int ans = min(solve(cost, n - 1), solve(cost, n - 2));
    return ans;
}

int solve2(vector<int> &cost, int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
        return cost[n];

    // Step 3: DP Result alreasy calculated
    if (dp[n] != -1)
        return dp[n];

    // Step 2:DP Store calculated Result in Dp
    dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return dp[n];
}

int minCostToClimbStairDp(vector<int> &cost)
{
    // Using reccursion Add memorisation in it
    // TC->O(N)
    // SC->O(N)+O(N)=O(N)

    int n = cost.size();

    // Step 1:DP
    vector<int> dp(n + 1, -1);
    int ans = min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return ans;
}

int minCostToClimbStairDpTab(vector<int> &cost)
{
    // TC->O(N)
    // SC->O(N)
    int n = cost.size();

    // Step 1:DP
    vector<int> dp(n + 1, -1);

    // Base case
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Step 2:DP Store calculated Result in Dp
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    // Minimum cost to reach the top (after last step)
    return min(dp[n - 1], dp[n - 2]);
}

int minCostToClimbStairDpSpaceOpt(vector<int> &cost)
{

    // TC->O(N)
    // SC->O(1)

    int n = cost.size();

    // Edge Case
    if (n == 1)
        return cost[0];

    if (n == 2)
        return min(cost[0], cost[1]);

    // base case
    int prev2 = cost[0];
    int prev1 = cost[1];

    if (n == 2)
        return min(prev1, prev2);

    int curr;

    // Step 2:DP Store calculated Result in Dp
    for (int i = 2; i < n; i++)
    {
        curr = min(prev2, prev1) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }

    // Minimum cost to reach the top (after last step)
    return min(prev1, prev2);
}

int main()
{
    // Test for maxDistinctWaysToClimbStair
    int nStair;
    cout << "Enter number of stairs (for max distinct ways): ";
    cin >> nStair;

    int totalWays = maxDistinctWaysToClimbStair(nStair, 0);
    cout << "Total distinct ways to climb " << nStair << " stairs (1 or 2 steps): " << totalWays << endl;

    // Now input cost array
    int n;
    cout << "\nEnter number of steps in cost array: ";
    cin >> n;

    vector<int> cost(n);
    cout << "Enter cost of each step:\n";
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    // Safety check
    if (cost.size() < 1)
    {
        cout << "Invalid cost array!" << endl;
        return 0;
    }

    cout << "\n Minimum Cost to Climb Stairs using different approaches:\n";

    if (n >= 2) // Only run recursive version if safe
        cout << "1. Recursion (TLE for large n): " << minCostToClimbStairRecc(cost) << endl;

    cout << "2. DP with Memoization: " << minCostToClimbStairDp(cost) << endl;
    cout << "3. DP with Tabulation: " << minCostToClimbStairDpTab(cost) << endl;
    cout << "4. Space Optimized DP: " << minCostToClimbStairDpSpaceOpt(cost) << endl;

    return 0;
}