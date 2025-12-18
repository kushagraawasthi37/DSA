#include <iostream>
#include <vector>
using namespace std;

int fiboTopDown(int n, vector<int> &dp)
{
    // Top Down Approach Reccursion+ memorisation
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n]; // check memoized result before computing

    dp[n] = fiboTopDown(n - 1, dp) + fiboTopDown(n - 2, dp);
    return dp[n];
}

int fiboTab(int n, vector<int> &dp)
{
    // Bottom up Approach Tabulisation

    // Base case ko already Dp Array mai store kara do
    // Step 3:
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        // step 2: base case se final ki taraf jao
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fiboSpace(int n)
{
    // Space Optimsation

    // Base case ko store kara lo
    int prev2 = 0;
    int prev1 = 1;

    int curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n;
    cout << "Enter Number\n";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Fibonacci number using Top down Approach " << fiboTopDown(n, dp) << endl;
    vector<int> dp2(n + 1, -1);
    cout << "Fibonacci number using Bottom Up Approach " << fiboTab(n, dp2) << endl;

    cout << "Fibonacci number using Space Optimisation Approach " << fiboSpace(n) << endl;

    return 0;
}