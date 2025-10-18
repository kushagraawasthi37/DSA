#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int maxCount = 0;
        while (right < nums.size())
        {
            while (right < nums.size() && nums[right] == 1)
            {
                right++;
            }
            while (right < nums.size() && nums[right] == 0)
            {
                maxCount = max(maxCount, right - left);
                right++;
                left = right;
            }
        }

        if (nums[nums.size() - 1] == 1)
        {
            maxCount = max(maxCount, right - left);
        }

        return maxCount;
    }
};
int main()
{
    return 0;
}