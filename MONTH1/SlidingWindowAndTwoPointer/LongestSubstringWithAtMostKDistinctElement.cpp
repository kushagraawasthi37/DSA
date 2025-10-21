#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to find the length of the longest
    substring with at most k distinct characters*/
    int kDistinctChar(string &s, int k)
    {

        /* Initialize left pointer, right pointer,
        and maximum length of substring*/
        int l = 0, r = 0, maxLen = 0;

        // Hash map to store character frequencies
        unordered_map<char, int> mpp;

        while (r < s.size())
        {

            // Increment frequency of current character
            mpp[s[r]]++;

            /* If the number of distinct characters
            exceeds k, shrink the window from the left*/
            while (mpp.size() > k)
            {

                // Decrement frequency of character at left pointer
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                {

                    /* Remove character from map
                    if its frequency becomes zero*/
                    mpp.erase(s[l]);
                }

                // Move left pointer to the right
                l++;
            }

            /* Update maximum length of substring with
            at most k distinct characters found so far*/
            if (mpp.size() <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            // Move right pointer
            r++;
        }
        // Return the maximum length found
        return maxLen;
    }
};

int main()
{
    string s = "aaabbccd";

    // Create an instance of the Solution class
    Solution sol;

    int res = sol.kDistinctChar(s, 2);

    // Output the result
    cout << "The maximum length of substring with at most " << 2 << " distinct characters is: " << res << endl;

    return 0;
}
