#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int> &nums, int k) {
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                maxCount = max(maxCount, i + 1);  // 0 based indexing
            }

            // calculate the sum of remaining part i.e., sum - k
            int rem = sum - k;

            // calculate the length and update maxLen
            if (prefixSum.find(rem) != prefixSum.end()) {
                maxCount = max(maxCount, i - prefixSum[rem]);
            }

            // update the map if sum is not already present
            if (prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }

        return maxCount;
    }


    int subarraySum(vector<int> &nums, int k) {
         int n = nums.size();
          int currentPrefixSum = 0;
          int count = 0;
          unordered_map<int, int> prefixSumMap;

          // Initialize the map with a default value for a 0 prefix sum
          prefixSumMap[0] = 1;

          for (int i = 0; i < n; i++) {
               // Add current element to the prefix sum
               currentPrefixSum += nums[i];

               // Calculate the value to remove (currentPrefixSum - k)
               int sumToRemove = currentPrefixSum - k;

               // Add the number of subarrays with the sum to be removed
               count += prefixSumMap[sumToRemove];

               // Update the count of current prefix sum in the map
               prefixSumMap[currentPrefixSum]++;
          }

          return count;
    }
};



int main(){

return 0;
}