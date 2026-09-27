class Solution {
private:
    int solve(vector<int>& arr, int i, int k, vector<int>& dp) {
        if (i >= arr.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        long long ans = 0;

        int maxi = INT_MIN;
        for (int j = i; j < arr.size() && j < i + k; j++) {
            maxi = max(maxi, arr[j]);
            int rem = solve(arr, j + 1, k, dp);
            ans = max(ans, (long long)maxi * (j - i + 1) + rem);
        }

        return dp[i] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, 0, k, dp);
    }
};