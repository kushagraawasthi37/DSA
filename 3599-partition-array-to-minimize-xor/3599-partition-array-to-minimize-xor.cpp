class Solution {

private:
    int solve(vector<int>& prefixXor, int part, int i, int n,
              vector<vector<int>>& dp) {

        if (part == 1) {
            return prefixXor[n] ^ prefixXor[i];
        }

        if (dp[part][i] != -1)
            return dp[part][i];

        int ans = INT_MAX;

        for (int j = i + 1; j <= n - (part-1); j++) {

            int currentXor = prefixXor[j] ^ prefixXor[i];

            int remaining = solve(prefixXor, part - 1, j, n, dp);

            int currentAnswer = max(currentXor, remaining);

            ans = min(ans, currentAnswer);
        }

        return dp[part][i] = ans;
    }

public:
    int minXor(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prefixXor(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ nums[i];
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(prefixXor, k, 0, n, dp);
    }
};