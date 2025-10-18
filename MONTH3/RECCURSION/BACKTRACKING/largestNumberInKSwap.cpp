#include <bits/stdc++.h>
using namespace std;

void solve(string &str, string &ans, int idx, int k)
{
    // base case
    if (idx == str.length() || k == 0)
    {
        return;
    }

    for (int i = idx; i < str.length(); i++)
    {

        // Give the maximum element in given range
        char remainingMaxiChar = *max_element(str.begin() + idx, str.end());

        if (str[idx] < str[i] && str[i] == remainingMaxiChar)
        {
            swap(str[i], str[idx]);

            // Updating the result
            if (str.compare(ans) > 0)
            {
                ans = str;
            }
            solve(str, ans, idx + 1, k - 1);
            swap(str[i], str[idx]);
        }
        else
        {
            // Horizontal drifting: k use nahi ho rha hai
            solve(str, ans, idx + 1, k);
        }
    }
}

int main()
{
    string str = "1234";
    string output = str;
    int idx = 0;
    int k = 2;
    solve(str, output, idx, k);
    cout << output << endl;

    return 0;
}
