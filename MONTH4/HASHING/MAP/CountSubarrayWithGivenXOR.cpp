
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithXorK(vector<int>& nums, int k)
    {
        int n = nums.size(); 
        int xr = 0;
        map<int, int> mpp; 
        // setting the value of 0.
        mpp[xr]++; 
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            // prefix XOR till index i:
            xr = xr ^ nums[i];

            // By formula: x = xr^k:
            int x = xr ^ k;

            // add the occurrence of xr^k to the count:
            cnt += mpp[x];

            // Insert the prefix xor till index i into the map:
            mpp[xr]++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    // Create an instance of the Solution class
    Solution solution;

    // Function call to get the result
    int ans = solution.subarraysWithXorK(a, k);

    cout << "The number of subarrays with XOR k is: " << ans << "\n";
    return 0;
}
