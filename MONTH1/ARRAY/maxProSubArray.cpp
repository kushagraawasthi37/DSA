#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);

            result = max(result, maxProd);
        }

        return result;
    }

    int maxProduct2(vector<int> &nums)
    {
        int prefix = 1;
        int suffix = 1;
        int n = nums.size();
        int result = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
            {
                prefix = 1;
            }

            if (suffix == 0)
            {
                suffix = 1;
            }

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - 1 - i];

            result = max(result, max(prefix, suffix));
        }

        return result;
    }
};

int main()
{
    return 0;
}