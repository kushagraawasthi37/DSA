#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x,
              int y)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Validity Check
        if (x < 0 || y < 0 || x >= m || y >= n)
            return INT_MAX;
        // Check Already stored solution
        if (dp[x][y] != INT_MAX)
            return dp[x][y];

        // Base case
        if (x == 0 && y == 0)
        {
            return dp[x][y] = matrix[x][y];
            cout << "Result " << dp[x][y] << endl;
        }
        int mini = INT_MAX;

        vector<int> validCol = {-1, 0, 1};
        for (int i = 0; i <= 2; i++)
        {
            int res = matrix[m-1][i]+solve(matrix, dp, x - 1, validCol[i] + y);
            cout << "Result " << res << endl;
            if (res != INT_MAX)
                mini = min(mini, res);
        }
        dp[x][y] = mini;
        // cout << "Precomputed DP res " << dp[x][y] << endl;
        return dp[x][y];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        int mini = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            mini = min(mini, solve(matrix, dp, m - 1, i));
        }

        return mini;
    }
};
int main()
{
    Solution S;
    vector<vector<int>> matrix = {{1, 2, 10, 4},
                                  {100, 3, 2, 1},
                                  {1, 1, 20, 2},
                                  {1, 2, 2, 1}};
    S.minFallingPathSum(matrix);
    return 0;
}