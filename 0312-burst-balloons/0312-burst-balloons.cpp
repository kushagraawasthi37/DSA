class Solution {
private:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        int& res = dp[i][j];
        if (res != -1)
            return res;

        int ans = INT_MIN;

        for (int k = i; k <= j; k++) {
            int cost = nums[i - 1] * nums[k] * nums[j + 1];
            int left = solve(nums, i, k - 1, dp);
            int right = solve(nums, k + 1, j, dp);

            ans = max(cost + left + right, ans);
        }

        return res = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        int sizee = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(sizee + 2, vector<int>(sizee + 2, -1));
        return solve(nums, 1, sizee, dp);
    }
};