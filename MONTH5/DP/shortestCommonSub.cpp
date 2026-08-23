#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solveTab(string &str1, string &str2)
    {
        int l1 = str1.length();
        int l2 = str2.length();

        // Step 1: Analyse the base case and fill the DP array
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        // step 2: Create the DP array
        for (int idx1 = l1 - 1; idx1 >= 0; idx1--)
        {
            for (int idx2 = l2 - 1; idx2 >= 0; idx2--)
            {
                int ans = 0;
                if (str1[idx1] == str2[idx2])
                {
                    ans = 1 + dp[idx1 + 1][idx2 + 1];
                }
                else
                {
                    ans += max(dp[idx1 + 1][idx2],
                               dp[idx1][idx2 + 1]);
                }

                dp[idx1][idx2] = ans;
            }
        }

        int len = dp[0][0];
        int i = 0, j = 1;

        string ans = "";

        for(auto row:dp){
            for(auto ele:row){
                cout<<ele<<" ";
            }
            cout<<endl;
        }

        while (i <=l1 && j <= l2)
        {
            if (str1[i] == str2[j])
            {
                ans += str1[i];
                i++;
                j++;
            }
            else if (dp[i + 1][j] > dp[i][j + 1])
            {
                ans += str1[i + 1];
                i++;
            }
            else
            {
                ans += str2[j + 1];
                j++;
            }
        }

        while (i < l1)
        {
            ans += str1[i++];
        }
       
        while (j < l2)
        {
            ans += str2[j++];
        }

        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        return solveTab(str1, str2);
    }
};

int main()
{
    string s1 = "brute";
    string s2 = "groot";

    // Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The Longest Common Supersequence is " << sol.shortestCommonSupersequence(s1, s2);
}