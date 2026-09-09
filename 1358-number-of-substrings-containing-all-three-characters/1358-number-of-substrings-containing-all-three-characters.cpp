class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 1);

        int l = 0;
        int r = 0;
        int ans = 0;
        int sizee = s.length();
        int cnt = 3;

        while (r < sizee) {
            freq[s[r] - 'a']--;

            if (freq[s[r] - 'a'] == 0)
                cnt--;

            if (cnt == 0) {
                ans += (sizee - r);

                while (cnt == 0) {
                    freq[s[l] - 'a']++;
                    if (freq[s[l] - 'a'] == 1)
                        cnt++;
                    l++;

                    if (cnt == 0) {

                        ans += (sizee - r);
                    }
                }
            }

            r++;
        }

        return ans;
    }
};