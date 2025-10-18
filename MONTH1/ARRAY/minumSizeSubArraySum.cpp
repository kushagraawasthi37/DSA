#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;               // sliding window ka start
        int right = 0;              // sliding window ka end
        int sum = 0;                // current window ka sum
        int minLength = INT_MAX;    // minimum length initialize
        bool isflag = false;        // check karne ke liye ki koi valid subarray mila ya nahi

        // poora array traverse karenge
        while (right < nums.size())
        {
            sum += nums[right];     // right character ko add karo window sum me

            // agar current sum target se bada ya equal hai
            while (sum >= target && left <= right)
            {
                isflag = true;                                  // valid subarray mila
                minLength = min(minLength, right - left + 1);  // min length update karo
                sum -= nums[left];                              // left element remove karo sum se
                left++;                                         // window start aage badhao
            }
            right++;  // window end aage badhao
        }

        if (isflag)  // agar koi valid subarray mila
        {
            return minLength;  // return minimum length
        }

        return 0;  // agar koi subarray nahi mila jo target >= sum ho
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << "Minimum length of subarray with sum >= " << target << " is: "
         << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}
