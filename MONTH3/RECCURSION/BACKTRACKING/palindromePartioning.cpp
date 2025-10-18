#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    string s2 = str;
    reverse(s2.begin(), s2.end());
    return str == s2;
}

void palindromePartioning(string str, vector<string> &partition, vector<vector<string>> &ans)
{
    if (str.length() == 0)
    {
        ans.push_back(partition);
        return;
    }

    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        string part = str.substr(0, i + 1);

        // LEFT STRING  PALINDROME HAI YA NHI
        if (isPalindrome(part))
        {
            partition.push_back(part);

            // CHECK FOR REMAINING STRING
            palindromePartioning(str.substr(i + 1), partition, ans);

            partition.pop_back();
        }
    }
}

int main()
{
    string str = "aabaa";
    vector<vector<string>> ans;
    vector<string> partition;
    palindromePartioning(str, partition, ans);

    for (const auto &row : ans)
    {
        for (const auto &str : row)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}