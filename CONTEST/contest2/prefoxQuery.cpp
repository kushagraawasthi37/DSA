#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(string s, vector<vector<int>> &queries)
    {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        // Powers of 10
        vector<long long> power(n + 1, 1);
        for (int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * 10) % MOD;

        // Prefix arrays
        vector<long long> prefCount(n, 0); // non-zero digits count
        vector<long long> prefSum(n, 0);   // sum of non-zero digits
        vector<long long> prefNum(n, 0);   // number formed by non-zero digits

        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                prefCount[i] = prefCount[i - 1];
                prefSum[i] = prefSum[i - 1];
                prefNum[i] = prefNum[i - 1];
            }

            if (s[i] != '0')
            {
                int d = s[i] - '0';
                prefCount[i]++;
                prefSum[i] += d;
                prefNum[i] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries)
        {
            int L = q[0];
            int R = q[1];

            long long totalDigits = prefCount[R] - (L > 0 ? prefCount[L - 1] : 0);
            long long digitSum = prefSum[R] - (L > 0 ? prefSum[L - 1] : 0);

            if (totalDigits == 0)
            {
                ans.push_back(0);
                continue;
            }

            long long rightPart = prefNum[R];
            long long leftPart = (L > 0 ? prefNum[L - 1] : 0);

            // Remove left part by shifting
            long long X = (rightPart - (leftPart * power[totalDigits]) % MOD + MOD) % MOD;

            long long result = (X * digitSum) % MOD;
            ans.push_back(result);
        }

        return ans;
    }
};

int main()
{
    class Solution sol;
    string s = "10203";
    vector<vector<int>> queries = {{0, 4}, {1, 3}};
    vector<int> results = sol.solve(s, queries);

    for (int res : results)
    {
        cout << res << endl;
    }

    return 0;
}