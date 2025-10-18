#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

long long int noOfDerangement(int n)
{
    // f(n)=(n-1)*(f(n-1)+f(n-2))
    // Koi bhi Index apni sahi position par na ho

    // Base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long long int ans = (n - 1) * (noOfDerangement(n - 1) + noOfDerangement(n - 2));
    return ans;
}
long long int solveMemo(int n, vector<long long int> &dp)
{
    // f(n)=(n-1)*(f(n-1)+f(n-2))
    // Koi bhi Index apni sahi position par na ho

    // Base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    // Step 3:
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Step 2:
    dp[n] = (n - 1) * (solveMemo(n - 2, dp) + solveMemo(n - 1, dp));

    return dp[n];
}

long long int countDerangementMemo(int n)
{
    vector<long long int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

long long int countDeerangementTab(int n)
{
    // f(n)=(n-1)*(f(n-1)+f(n-2))
    // Koi bhi Index apni sahi position par na ho

    vector<long long int> dp(n + 1, -1);

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    // Base case
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        // Step 2:
        dp[i] = (i - 1) * ((dp[i - 1]) + dp[i - 2]);
    }

    return dp[n];
}
long long int countDeerangementSpaceOpt(int n)
{
    // f(n)=(n-1)*(f(n-1)+f(n-2))
    // Koi bhi Index apni sahi position par na ho

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long long int prev2 = 0;
    long long int prev1 = 1;

    // Base case

    long long int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (i - 1) * (prev2 + prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int main()
{
    return 0;
}