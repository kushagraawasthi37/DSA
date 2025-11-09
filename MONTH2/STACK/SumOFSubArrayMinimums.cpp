#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to find the sum of the
    minimum value in each subarray */
    int sumSubarrayMins(vector<int> &arr)
    {

        // Size of array
        int n = arr.size();

        int mod = 1e9 + 7; // Mod value

        // To store the sum
        int sum = 0;

        // Traverse on the array
        for (int i = 0; i < n; i++)
        {

            // To store the minimum of subarray
            int mini = arr[i];

            /* Nested loop to get all
            subarrays starting from index i */
            for (int j = i; j < n; j++)
            {

                // Update the minimum value
                mini = min(mini, arr[j]);

                // Update the sum
                sum = (sum + mini) % mod;
            }
        }

        // Return the computed sum
        return sum;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 5};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to find the sum of the
    minimum value in each subarray */
    int ans = sol.sumSubarrayMins(arr);

    cout << "The sum of minimum value in each subarray is: " << ans;

    return 0;
}