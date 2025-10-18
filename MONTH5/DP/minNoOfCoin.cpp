#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveRec(vector<int> &num, int x)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return INT32_MAX;

    int mini = INT32_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRec(num, x - num[i]);
        if (ans != INT32_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }

    return mini;
}

int targetSumRec(vector<int> &num, int sum)
{

    // Time complexity: Exponential (O(n^sum)) due to overlapping subproblems.
    // It will Time Limit Exceed (TLE) for inputs like sum = 1000, num = {1, 2}.

    int ans = solveRec(num, sum);
    if (ans == INT32_MAX)
        return -1;

    return ans;
}

/*******************DP->Top Down approach Reccusrion+ Memorisation********************/

int solveDpMem(vector<int> &num, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return INT32_MAX;

    // Step 3: Base case ke baadd jake dp Array ko check kro
    if (dp[x] != -1)
        return dp[x];

    int mini = INT32_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveDpMem(num, x - num[i], dp);
        if (ans != INT32_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }

    // Step2 :Update Dp
    dp[x] = mini;
    return dp[x];
}

int targetSumDpMem(vector<int> &num, int sum)
{
    // TC->     O(n * x)
    // SC-> 	O(x)	Efficient, uses recursion
    int n = num.size();

    // Step 1:
    vector<int> dp(sum + 1, -1);

    int ans = solveDpMem(num, sum, dp);

    if (ans == INT32_MAX)
        return -1;

    return ans;
}
/*******************DP->Bottom Up approach Tabulation  ********************/

int solveDpTab(vector<int> &num, int x, vector<int> &dp)
{

    // 0 ko banane mai 0 coin lagenge
    dp[0] = 0;

    // Step 3: Base case ke baadd jake dp Array ko check kro

    for (int i = 1; i <= x; i++)
    {
        // dp[i]=Minimum  number of element to make i
        // trying to solve for every amount figure from 1 to x

        for (int j = 0; j < num.size(); j++)
        {

            // valid Index hai ya nahi
            if (i - num[j] >= 0 && dp[i - num[j]] != INT32_MAX)
            {
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
            }
        }
    }

    if (dp[x] == INT32_MAX)
        return -1;

    return dp[x];
}

int targetSumDptab(vector<int> &num, int sum)
{
    // TC->     O(n * x) n-> no of coin  x-> sum
    // SC-> 	O(x)	Efficient, uses Iteration

    int n = num.size();

    // Step 1:
    vector<int> dp(sum + 1, INT32_MAX);

    int ans = solveDpTab(num, sum, dp);

    if (ans == INT32_MAX)
        return -1;

    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 5;

    cout << "Recursive: " << targetSumRec(nums, target) << endl;
    cout << "Memorization: " << targetSumDpMem(nums, target) << endl;
    cout << "Tabulation: " << targetSumDptab(nums, target) << endl;

    return 0;
}
