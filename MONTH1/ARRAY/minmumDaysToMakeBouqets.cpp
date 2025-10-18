#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValidDay(vector<int> nums, int mid, int roses, int bouquet)
    {
        long long currentBouqet = 0;
        long long currentRoses = 0;

        for (int high = 0; high < nums.size(); high++)
        {
            if ((long long)nums[high] > (long long)mid)
            {
                currentRoses = 0;
                continue;
            }
            else
            {
                currentRoses++;
                if (currentRoses == (long long)roses)
                {
                    currentRoses = 0; // Reset the roses
                    currentBouqet++;
                }
            }
        }

        if (currentBouqet >= (long long)bouquet)
        {
            return true;
        }

        return false;
    }

public:
    int roseGarden(int n, vector<int> nums, int k, int m)
    {
        long long maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxi)
            {
                maxi = max(maxi, (long long)nums[i]);
            }
        }

        if ((long long)m * (long long)k > (long long)n)
        {
            return -1;
        }

        long long s = 0;
        long long e = maxi;
        long long ans;

        while (s <= e)
        {
            long long mid = s + (e - s) / 2;

            if (isValidDay(nums, mid, k, m))
            {
                ans = mid;   // Can be potential answer
                e = mid - 1; // Check for more accurate answer
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