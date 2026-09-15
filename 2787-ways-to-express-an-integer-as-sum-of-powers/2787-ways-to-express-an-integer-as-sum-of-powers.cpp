
class Solution {

private:
    const int MOD = 1e9 + 7;

    long long findExpo(int a, int x) {
        long long res = 1;
        while (x--) {
            res *= a;
        }
        return res;
    }

public:
    int numberOfWays(int n, int x) {
        vector<int> arr;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1;; i++) {
            int p = findExpo(i, x);

            if (p <= n) {
                for (int target = n; target >= p; target--) {
                    dp[target] = (dp[target] + dp[target - p]) % MOD;
                }
            } else
                break;
        }

        return dp[n];
    }
};