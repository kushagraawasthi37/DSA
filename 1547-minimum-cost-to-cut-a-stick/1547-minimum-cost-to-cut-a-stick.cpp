class Solution {

private:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {

        if (i > j)
            return 0;

        int& res = dp[i][j];
        if (res != -1)
            return res;

        int ans = INT_MAX;

        for (int k = i; k <= j; k++) {
            int curr = cuts[j + 1] - cuts[i - 1];
            int left = solve(cuts, k+1, j, dp);
            int right = solve(cuts, i, k - 1, dp);

            ans = min(ans, curr + right + left);
        }

        return res = ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int sizee = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(sizee + 3, vector<int>(sizee + 3, -1));

        return solve(cuts, 1, sizee , dp);
    }
};


//  0 1 3 4 5 7