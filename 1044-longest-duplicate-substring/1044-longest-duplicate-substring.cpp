class Solution {
public:
    bool check(string& s, int len, int& index) {
        int p = 31;
        const int mod = 1e9 + 7;
        int power = 1;
        int hash = 0;

        for (int i = 1; i < len; i++) {
            power = ((long long)power * p) % mod;
        }

        for (int i = 0; i < len; i++) {
            hash = (((long long)hash * p) % mod + (s[i] - 'a' + 1)) % mod;
        }

        unordered_map<int, int> m;

        for (int i = 0; i <= s.length() - len; i++) {
            if (m.count(hash) > 0) {
                if (s.substr(i, len) == s.substr(m[hash], len)) {
                    index = i;
                    return true;
                }
            }

            m[hash] = i;

            if (i + len < s.length())
                hash = (hash - ((long long)(s[i] - 'a' + 1) * (long long)power % mod) + mod) % mod;
            hash =
                ((long long)hash * (long long)p) % mod + (s[i + len] - 'a' + 1);
        }

        return false;
    }

    string longestDupSubstring(string s) {

        int n = s.size();

        int low = 1;
        int high = n - 1;

        int ansIndex = -1;
        int ansLength = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int index = -1;

            if (check(s, mid, index)) {

                ansIndex = index;
                ansLength = mid;

                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (ansIndex == -1)
            return "";

        return s.substr(ansIndex, ansLength);
    }
};