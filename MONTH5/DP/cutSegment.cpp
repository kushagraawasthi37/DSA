#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

int cutSegment(int n, int x, int y, int z)
{
    int ans = solve(n, x, y, z);
    if (ans < 0)
        return 0;
    else
    {
        return ans;
    }
}

int solveMemo(int n, int x, int y, int z, vector<int> &dp)
{
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;

    // step 3:
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = 1 + solveMemo(n - x, x, y, z, dp);
    int b = 1 + solveMemo(n - y, x, y, z, dp);
    int c = 1 + solveMemo(n - z, x, y, z, dp);

    dp[n] = max(max(a, b), c);

    return dp[n];
}

int cutSegmentReccMemo(int n, int x, int y, int z)
{
    // step 1:
    vector<int> dp(n + 1, -1);

    int ans = solveMemo(n, x, y, z, dp);
    if (ans == INT_MIN)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}

int cutSegmenttab(int n, int x, int y, int z)
{

    // step 1:
    vector<int> dp(n + 1, INT_MIN);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        // x is a valid index
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        // y is a valid index
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        // z is a valid index
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    if (dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int main()
{
    int n = 7, x = 5, y = 2, z = 2;

    cout << "Recursive: " << cutSegment(n, x, y, z) << endl;
    cout << "Memoized: " << cutSegmentReccMemo(n, x, y, z) << endl;
    cout << "Tabulated: " << cutSegmenttab(n, x, y, z) << endl;

    return 0;
}
