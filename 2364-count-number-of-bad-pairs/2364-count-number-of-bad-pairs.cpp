class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        long long total = 0;
        long long ans = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            ans += (total - m[i - nums[i]]);
            total++;
            m[i - nums[i]]++;
        }

        return ans;
    }
};