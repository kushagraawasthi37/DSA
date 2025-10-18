#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string s, unordered_map<string, int> &m, bool &ans)
    {

        if (ans)
        {
            return;
        }

        if (s.length() == 0)
        {
            ans = true;
            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            string left = s.substr(0, i + 1);
            if (m.find(left) != m.end())
            {
                solve(s.substr(i + 1), m, ans);
            }
        }
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> m;
        bool ans = false;
        // Storing all the word in map for fast search
        for (auto ele : wordDict)
        {
            m[ele]++;
        }

        solve(s, m, ans);

        return ans;
    }
};

// TLE  IN LEETCODE USE DP FOR SOLVING THIS
int main()
{

    return 0;
}