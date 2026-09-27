class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();

        const long long MOD = 1e9 + 7;
        const long long BASE = 31;

        vector<long long> power(n + 1);
        vector<long long> pref(n + 1);

        power[0] = 1;

        for (int i = 0; i < n; i++) {
            power[i + 1] = power[i] * BASE % MOD;

            pref[i + 1] =
                (pref[i] * BASE + (s[i] - 'a' + 1)) % MOD;
        }

        auto getHash = [&](int l, int r) {
            return (pref[r] -
                    pref[l] * power[r - l] % MOD +
                    MOD) % MOD;
        };

        auto check = [&](int len) -> int {

            unordered_map<long long, vector<int>> mp;

            for (int i = 0; i + len <= n; i++) {

                long long h = getHash(i, i + len);

                // Same hash -> verify actual strings
                for (int j : mp[h]) {

                    if (s.compare(i, len, s, j, len) == 0) {
                        return i;
                    }
                }

                mp[h].push_back(i);
            }

            return -1;
        };

        int lo = 1;
        int hi = n - 1;

        int ansStart = -1;
        int ansLen = 0;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            int start = check(mid);

            if (start != -1) {
                ansStart = start;
                ansLen = mid;

                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        if (ansStart == -1)
            return "";

        return s.substr(ansStart, ansLen);
    }
};