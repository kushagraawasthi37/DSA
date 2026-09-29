class Solution {
private:
    double solve(vector<int>& prefix, int i, int part,
                 vector<vector<double>>& dp) {


        if (part == 1) {
            return (prefix[prefix.size() - 1] - prefix[i]) * 1.0 /
                   (prefix.size() - 1 - i);
        }

        if (dp[part][i] != -1)
            return dp[part][i];

        double ans = INT_MIN;
        for (int j = i + 1; j <= prefix.size() - part ; j++) {
            double curr = (prefix[j] - prefix[i]*1.0) / (j - i) ;
            double rem = solve(prefix, j, part - 1, dp);
            ans = max(ans, curr + rem);
        }

        return dp[part][i] = ans;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(k + 2, vector<double>(nums.size() + 2, -1));
        return solve(prefix, 0, k, dp);
    }
};