#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int left = 0, right = 0; // sliding window start (left) and end (right)
        int product = 1;         // current window ka product
        int count = 0;           // number of valid subarrays
        int n = nums.size();

        if (k <= 1) // agar k <= 1 hai, koi subarray valid nahi ho sakta
            return 0;

        // poora array traverse karenge
        while (right < n)
        {
            product *= nums[right]; // window expand karo right se

            // agar product >= k hai, window ko shrink karo left se
            while (product >= k)
            {
                product /= nums[left]; // left element remove karo product se
                left++;                // left pointer aage badhao
            }

            // ab window me jitne subarrays possible hai, unko count karo
            // formula: 1 + (right - left) => current element + jitne elements left se include
            count += 1 + (right - left);

            right++; // right pointer aage badhao
        }

        return count; // total subarrays return karo
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Number of subarrays with product < " << k << " is: "
         << sol.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}
