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

    string transform(string s) {
        string temp = "#";
        int i = 0;
        while (i < s.length()) {
            temp.push_back(s[i++]);
            temp.push_back('#');
        }
        return temp;
    }

    string manachers(string t) {
        string temp = t;
        t = transform(t);

        for (auto ch : t) {
            cout << ch;
        }

        int n = t.length();

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int center = 0;
        int k;

        vector<int> lps(n, 0);

        for (int i = 0; i < t.length(); i++) {
            if (i > r) {
                k = 0;
            } else {

                int j = l + r - i;
                if (j - lps[j] > l) {
                    lps[i] = lps[j];
                    continue;
                } else {
                    k = r - i;
                }
            }

            while (i - k >= 0 && i + k < t.length() && t[i - k] == t[i + k]) {
                k++;
            }

            k--;
            lps[i] = k;

            if (k > maxLen) {
                maxLen = k;
                center = i / 2;
            }

            if (i + k > r) {
                r = i + k;
                l = i - k;
            }
        }

        return temp.substr(center - (maxLen / 2), maxLen);
    }

public:
    string longestPalindrome(string s) {
        // return solve(s);
        return manachers(s);
    }
};