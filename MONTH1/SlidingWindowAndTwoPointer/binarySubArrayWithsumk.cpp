#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to find the number of
    subarrays with sum equal to `goal`*/
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        /*Calculate the number of subarrays with
        sum exactly equal to `goal` by using the
        difference between subarrays with sum less
        than or equal to `goal` and those with sum
        less than or equal to `goal-1`*/
        return numSubarraysWithSumLessEqualToGoal(nums, goal) - numSubarraysWithSumLessEqualToGoal(nums, goal - 1);
    }

private:
    /* Helper function to find the number of
    subarrays with sum less than or equal to `goal`*/
    int numSubarraysWithSumLessEqualToGoal(vector<int> &nums, int goal)
    {
        if (goal < 0)
        {
            return 0;
        }

        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        int n = nums.size();
        while (r < n)
        {
            sum += nums[r];

            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            count = count + r - l + 1;
            r++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {1, 0, 0, 1, 1, 0};
    int goal = 2;

    // Create an instance of Solution class
    Solution sol;

    int ans = sol.numSubarraysWithSum(nums, goal);

    // Print the result
    cout << "Number of substrings with sum \"" << goal << "\" is: " << ans << endl;

    return 0;
}
