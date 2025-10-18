#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void solve(string s, string &temp, vector<string> &res, unordered_set<string> &set)
    {
        if (s.length() == 0)
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            string left = s.substr(0, i + 1);
            if (set.find(left) != set.end())
            {
                int length_before = temp.length();
                if (i != s.length() - 1)
                {
                    temp = temp + left + " ";
                }
                else
                {
                    temp = temp + left;
                }
                solve(s.substr(i + 1), temp, res, set);
                temp.erase(length_before);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> res;
        string temp = "";
        unordered_set<string> set;
        for (auto ele : wordDict)
        {
            set.insert(ele);
        }

        solve(s, temp, res, set);
        return res;
    }
};

int main()
{

    return 0;
}