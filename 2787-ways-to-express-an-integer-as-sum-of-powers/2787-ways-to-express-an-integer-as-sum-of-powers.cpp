
class Solution {

private:
    const int MOD = 1e9 + 7;

    long long findExpo(int x, int n) {

        long long ans = 1;
        long long base = x;

        while (n) {

            if (n & 1) {
                ans *= x;
            }


            x = (long long)x * (long long)x;

            n >>= 1;
        }

        return ans;
    }

    int solve(vector<int>& arr, int idx, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return 1;
        if (idx == arr.size() || target < 0)
            return 0;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        dp[idx][target] =
            ((long long)(solve(arr, idx + 1, target - arr[idx], dp)) +
             (long long)solve(arr, idx + 1, target, dp)) %
            MOD;

        return dp[idx][target] % MOD;
    }

public:
    int numberOfWays(int n, int x) {
        if (n == 1)
            return 1;

        int maxi = 0;

        int s = 0;
        int e = n;
        while (s <= e) {
            int mid = (s + e) >> 1;

            int res = findExpo(mid, x);
            if (mid == 2)
                cout << res << " ";

            if (findExpo(mid, x) <= (long long)n) {
                maxi = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        // cout << maxi;

        vector<int> arr;

        for (int i = 1; i <= maxi; i++) {
            arr.push_back(findExpo(i, x));
        }

        for (auto ele : arr) {
            // cout<<ele<<" ";
        }

        vector<vector<int>> dp(arr.size() + 1, vector<int>(n + 1, -1));
        return solve(arr, 0, n, dp);
        // return 0;
    }
};