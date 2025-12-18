#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rev(int x)
    {
        int r = 0;
        while (x > 0)
        {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }

public:
    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];

            // Check if this value matches reverse of some previous number
            if (mp.count(val))
            {
                ans = min(ans, i - mp[val]);
            }

            // Always update reverse(val) index
            mp[rev(val)] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
©leetcode int main()
{
    vector<int> nums = {42, 11, 1, 24};
    Solution sol;
    cout << sol.minMirrorPairDistance(nums) << endl;
    return 0;
}