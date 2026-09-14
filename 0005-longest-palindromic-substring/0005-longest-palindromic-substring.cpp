class Solution {
private:
    string solve(string& s) {
        int maxLen = 0;
        int st;

        for (int i = 0; i < s.length(); i++) {
            int l = i;
            int r = i;

            while (l >= 0 && r < s.length() && s[l] == s[r]) {

                if (maxLen < r - l + 1) {
                    maxLen = r - l + 1;
                    st = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while (l >= 0 && r < s.length() && s[l] == s[r]) {

                if (maxLen < r - l + 1) {
                    maxLen = r - l + 1;
                    st = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(st, maxLen);
    }

public:
    string longestPalindrome(string s) { return solve(s); }
};