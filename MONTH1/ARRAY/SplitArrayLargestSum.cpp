#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool isValidSolution(vector<int> nums, int k, int mid)
    {
        int subArrayCount = 1;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (currSum + nums[i] <= mid)
            {
                currSum += nums[i];
            }
            else
            {
                subArrayCount++;
                if (subArrayCount > k)
                {
                    return false;
                }
                currSum = nums[i];
            }
        }
        return true;
    }

public:
    int largestSubarraySumMinimized(vector<int> &nums, int k)
    {

        // Minimum Sum jo hoga wo maximum element ke equal ho skta hai
        int s = INT_MIN;

        // Maximum sum total sum ke equal ho skta hai
        int e = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            e += nums[i];
            s = max(s, nums[i]);
        }

        int ans;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isValidSolution(nums, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}