#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestNonRepeatingSubstring(string &s)
    {
        // your code goes here
        unordered_map<char, int> m;

        int l = 0, r = 0;
        int maxLen = 0;

        while (r < s.length())
        {
            char ch = s[r];

            // Checking if the character 'ch' is already present in the current substring`.
            if (m[ch] == 0)
            {
                maxLen = max(maxLen, r - l + 1);
                m[ch]++;
            }
            else
            {
                while (s[l] != s[r])
                {
                    m[s[l]]--;
                    l++;
                }
                l++;
            }
            r++;
        }

        return maxLen;
    }
};

int main()
{
    string s = "cadbzabcd";

    // Create an instance of the Solution class
    Solution sol;

    int result = sol.longestNonRepeatingSubstring(s);

    // Output the maximum length
    cout << "The maximum length is:\n";
    cout << result << endl;

    return 0;
}
