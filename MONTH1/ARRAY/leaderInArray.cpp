#include<bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        int leader = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > leader) {
                ans.push_back(nums[i]);
                leader = nums[i];
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
int main(){
    return 0;
}