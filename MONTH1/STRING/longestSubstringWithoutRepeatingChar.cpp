#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;   // sliding window ka start
        int right = 0;  // sliding window ka end
        int maxLength = 0;  // longest substring ka length
        unordered_map<char, bool> m;  // map to track characters present in current window

        // poora string traverse karenge
        while (right < s.length())
        {
            if (!m[s[right]])  // agar current character window me nahi hai
            {
                m[s[right]] = true;  // character ko mark kar do window me present
                maxLength = max(maxLength, right - left + 1);  // max length update karo
            }
            else  // agar duplicate character mil gaya
            {
                // left ko aise move karo jab tak duplicate hat nahi jata
                while (m[s[right]])
                {
                    m[s[left]] = false;  // left character ko window se remove karo
                    left++;              // window start aage badhao
                }
                m[s[right]] = true;  // ab duplicate character ko add karo
            }
            right++;  // window ka end aage badhao
        }
        return maxLength;  // longest substring return karo
    }
};

int main()
{
    // Example usage
    Solution sol;
    string str = "abba";
    cout << "Length of longest substring without repeating characters: " 
         << sol.lengthOfLongestSubstring(str) << endl;
    return 0;
}
