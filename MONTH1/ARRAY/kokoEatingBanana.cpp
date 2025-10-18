
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long hoursToEatAllBanana(vector<int> nums, long long mid)
    {
        long long totalHours = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalHours += (long long)ceil((double)nums[i] / (double)mid);
        }
        return totalHours;
    }

public:
    int minimumRateToEatBananas(vector<int> nums, int h)
    {
        long long maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max((long long)nums[i], maxi);
        }

        if (nums.size() > h)
        {
            return -1;
        }

        long long s = 1;
        long long e = maxi;
        long long ans = 0;

        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            long long totalHours = hoursToEatAllBanana(nums, mid);

            if (totalHours <= h)
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