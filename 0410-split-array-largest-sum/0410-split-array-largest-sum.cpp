class Solution {

private:
    int solve(vector<int>& prefix, int i, int part, vector<vector<int>>& dp) {
        if (part == 1) {
            return prefix[prefix.size() - 1] - prefix[i];
        }

        if (dp[i][part] != -1)
            return dp[i][part];

        int ans = INT_MAX;

        for (int j = i + 1; j <= prefix.size() - (part - 1); j++) {
            int curr = prefix[j] - prefix[i];
            int rem = solve(prefix, j, part - 1, dp);

            ans = min(ans, (max(curr, rem)));
        }

        return dp[i][part] = ans;
    }

    // bool isValid(vector<int>& nums, int mid, int k) {
    //     int curr = 0;
    //     int currArr = 1;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (curr + nums[i] > mid) {
    //             currArr++;
    //             curr = nums[i];
    //             if (currArr > k)
    //                 return false;
    //         } else {
    //             curr = curr + nums[i];
    //         }
    //     }

    //     return currArr <= k;
    // }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return solve(prefix, 0, k, dp);

        // int s = *max_element(nums.begin(), nums.end());
        // int e = accumulate(nums.begin(), nums.end(), 0);

        // int ans = e;

        // while (s <= e) {
        //     int mid = (s + ((e - s) >> 1));

        //     cout << s << " " << e << " " << mid << endl;

        //     if (isValid(nums, mid, k)) {
        //         ans = mid;
        //         e = mid - 1;
        //     } else
        //         s = mid + 1;
        // }

        // return ans;
    }
};