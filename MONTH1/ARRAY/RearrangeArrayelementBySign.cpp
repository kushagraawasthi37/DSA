#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, idx = 0;
        vector<int> result(n);

        while (idx < n) {
            if (nums[idx] > 0) {
                result[i] = nums[idx];
                idx++;
                i += 2;

            } else {
                result[j] = nums[idx];
                idx++;
                j += 2;
            }
        }

        return result;
    }
};


int main(){

return 0;
}