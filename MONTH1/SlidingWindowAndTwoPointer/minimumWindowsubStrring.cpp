#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to find the minimum length
    substring in string s that contains
    all characters from string t. */
    string minWindow(string s, string t)
    {

        /* Variable to store the minimum
        length of substring found */
        int minLen = INT_MAX;

        /* Variable to store the starting index
        of the minimum length substring */
        int sIndex = -1;

        /* Array to count frequencies
        of characters in string t*/
        int hash[256] = {0};

        // Count the frequencies of characters in t
        for (char c : t)
        {
            hash[c]++;
        }

        int count = 0;
        int l = 0, r = 0;

        // Iterate through current window
        while (r < s.size())
        {
            // Include the current character in the window
            if (hash[s[r]] > 0)
            {
                count++;
            }
            hash[s[r]]--;

            /* If all characters from t
            are found in current window */
            while (count == t.size())
            {

                /* Update minLen and sIndex
                if current window is smaller */
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                // Remove leftmost character from window
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                {
                    count--;
                }
                l++;
            }
            r++;
        }

        // Return minimum length substring from s
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};

int main()
{
    string s = "ddaaabbca";
    string t = "abc";

    // Create an instance of Solution class
    Solution sol;

    string ans = sol.minWindow(s, t);

    // Print the result
    cout << "Minimum length substring containing all characters from \"" << t << "\" is: " << ans << endl;

    return 0;
}
