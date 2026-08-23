#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &nums, int k)
    {
        long long org_sum = (long long)(nums[0] * prices[0]);
        int n = prices.size();
        vector<long long> prefixPro(n);
        prefixPro[0] = org_sum;
        for (int i = 1; i < n; i++)
        {
            org_sum += (long long)(nums[i] * prices[i]);
            prefixPro[i] = org_sum;
        }

        int l = 0;
        int r = 0;
        int pos_left = -1;
        int pos_right = -1;
        int tempPro = INT_MAX;

        while (r < n)
        {
            r++;
            if ((r - l + 1) == k)
            {
                int pro = prefixPro[r];
                if (l > 0)
                {
                    pro -= prefixPro[l - 1];
                }
                if (pro < tempPro)
                {
                    pos_left = l;
                    pos_right = r;
                    tempPro = pro;
                }
                l++;
            }
        }

        // cout << "Left " << pos_left << endl;
        // cout << "Right " << pos_right << endl;
        long long temp_sum = 0;
        if (pos_left > 0)
        {
            temp_sum = prefixPro[pos_left - 1];
            // cout << "Temp sum before the left " << temp_sum << endl;
        }
        // cout << "Temp sum before the left " << temp_sum << endl;

        for (int i = pos_left + k / 2; i <= pos_right; i++)
        {

            // cout << "i :" << i << endl;
            // cout << "Temp sum : " << temp_sum << endl;
            temp_sum += prices[i];
            // cout << "Temp sum : " << temp_sum << endl;
        }
        for (int i = pos_right + 1; i < nums.size(); i++)
        {
            temp_sum += (nums[i] * prices[i]);
        }

        // cout << "Modifiedd Sum " << temp_sum;

        return max(temp_sum, org_sum);
    }
};
int main()
{
    vector<int> prices = { 4,2,8};
    vector<int> stratgies = {-1,0, 1};

    Solution S;
    cout << S.maxProfit(prices, stratgies, 2);

    return 0;
}