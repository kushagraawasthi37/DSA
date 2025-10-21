#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruits(vector<int> &nums)
    {
        int type1 = -1;
        int type2 = -1;
        int type1Idx = -1;
        int type2Idx = -1;
        int l = 0, r = 0;
        int maxLength = 0;
        int n = nums.size();

        while (r < n)
        {
            int curr = nums[r];

            // assign first or second type if empty
            if (type1 == -1 || curr == type1)
            {
                type1 = curr;
                type1Idx = r;
            }
            else if (type2 == -1 || curr == type2)
            {
                type2 = curr;
                type2Idx = r;
            }
            else
            {
                // third type encountered → remove the one that appeared earlier
                if (type1Idx < type2Idx)
                {
                    l = type1Idx + 1;
                    type1 = curr;
                    type1Idx = r;
                }
                else
                {
                    l = type2Idx + 1;
                    type2 = curr;
                    type2Idx = r;
                }
            }

            // update last seen index for the current fruit
            if (curr == type1)
                type1Idx = r;
            if (curr == type2)
                type2Idx = r;

            // update max window size
            maxLength = max(maxLength, r - l + 1);
            r++;
        }

        return maxLength;
    }

    // For general “at most k distinct elements” problems -> totalFruitsmpp (map version) is more flexible and safer.
    int totalFruitsmpp(vector<int> &fruits)
    {

        // Length of the input array
        int n = fruits.size();
        int maxLen = 0;
        unordered_map<int, int> mpp;
        int l = 0, r = 0;

        while (r < n)
        {
            mpp[fruits[r]]++;
            if (mpp.size() > 2)
            {
                while (mpp.size() > 2)
                {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0)
                    {
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }

            if (mpp.size() <= 2)
            {
                maxLen = max(maxLen, r - l + 1);
            }

            r++;
        }

        // Return the maximum fruit
        return maxLen;
    }
};

int main()
{
    vector<int> input = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    // Create an instance of Solution class
    Solution sol;

    int length = sol.totalFruits(input);

    // Print the result
    cout << "Maximum fruits the can have is: " << length << endl;

    return 0;
}