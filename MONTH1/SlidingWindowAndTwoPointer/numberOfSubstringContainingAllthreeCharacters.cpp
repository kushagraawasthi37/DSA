#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        // your code goes here
        int l = 0;
        int r = 0;
        int n = s.length();
        int cnt = 0;
        int total = 0;

        vector<int> hash(3, 1);

        while (r < n)
        {
            if (hash[s[r] - 'a'] > 0)
            {
                cnt++;
            }
            hash[s[r] - 'a']--;

            while (r - l >= 2 && cnt == 3)
            {
                total += n - r;

                hash[s[l] - 'a']++;
                if (hash[s[l] - 'a'] > 0)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return total;
    }
};

int main()
{
    string s = "bbacba";

    // Create an instance of Solution class
    Solution sol;

    int ans = sol.numberOfSubstrings(s);

    // Print the result
    cout << "Number of substrings containing 'a', 'b', 'c' in \"" << s << "\" is: " << ans << endl;

    return 0;
}
