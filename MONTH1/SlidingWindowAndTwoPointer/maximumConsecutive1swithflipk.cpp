#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // your code goes here
        int right = 0;
        int left = 0;
        int maxLen = 0;
        int n = nums.size();

        while (right < n)
        {
            if (nums[right] == 0)
            {
                if (k > 0)
                {
                    maxLen = max(maxLen, right - left + 1);
                    right++;
                    k--;
                }
                else if (k <= 0)
                {
                    if (nums[left] == 0)
                        k++;
                    left++;
                }
            }
            else
            {
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }

        return maxLen;
    }
};
int main()
{

    return 0;
}