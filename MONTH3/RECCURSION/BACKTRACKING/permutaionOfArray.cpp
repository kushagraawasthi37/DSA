#include <bits/stdc++.h>
using namespace std;

void getpermutation(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    // TC->O(n!*n)
    // SC->O(n!+n)=>O(n!)

    int n = nums.size();

    if (idx == n)
    {
        ans.push_back(nums);
        return ;
    }

    unordered_map<int, int> m;

    for (int i = idx; i < n; i++)
    {
        if (m.find(nums[i]) == m.end())
        {
            m[nums[i]]++;
            swap(nums[idx], nums[i]);

            getpermutation(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    return;
}

void printAllPermutation(vector<vector<int>> &vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << "{";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            cout << vec[i][j];
            if (j + 1 < vec[i].size())
                cout << ", ";
        }
        cout << "}";
        if (i + 1 < vec.size())
            cout << ", ";
    }
    cout << "}" << endl;
}

int main()
{
    vector<int> vec = {1, 2, 3,3};
    vector<vector<int>> ans;
    getpermutation(vec, 0, ans);
    printAllPermutation(ans);

    return 0;
}