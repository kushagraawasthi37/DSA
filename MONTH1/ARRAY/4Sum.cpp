#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &vec, int tar)
{
    int n = vec.size();
    vector<vector<int>> ans;

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n - 3; i++)
    {
        // Repeating result Avoid
        if (i > 0 && vec[i] == vec[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && vec[j] == vec[j - 1])
            {
                continue;
            }

            int p = j + 1, q = n - 1;
            while (p < q)
            {
                long long sum = vec[i] + vec[j] + vec[p] + vec[q];

                if (sum > tar)
                {
                    q--;
                }
                if (sum < tar)
                {
                    p++;
                }
                if (sum == tar)
                {
                    ans.push_back({vec[i], vec[j], vec[p], vec[q]});
                    p++;
                    q--;

                    // Remove Duplicate
                    while (p < q && vec[p] == vec[p + 1])
                    {
                        p++;
                    }
                    while (q > p && vec[q] == vec[q - 1])
                        q--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {-2, -1, -1, 1, 1, 2, 2};
    vector<vector<int>> ans = fourSum(v, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}