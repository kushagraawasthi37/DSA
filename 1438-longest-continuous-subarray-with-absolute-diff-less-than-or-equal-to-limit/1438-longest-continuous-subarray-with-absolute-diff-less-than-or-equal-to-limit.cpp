class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> m;

        int l = 0;
        int r = 0;

        int ans = 0;

        while (r < nums.size()) {
            m[nums[r]]++;

            if (abs(m.begin()->first - m.rbegin()->first) <= limit) {
                ans = max(ans, r - l + 1);
            }
            else {
                while (l < r && !m.empty() &&
                       abs(m.begin()->first - m.rbegin()->first) > limit) {
                    m[nums[l]]--;
                    if (m[nums[l]] <= 0) {
                        m.erase(nums[l]);
                    }
                    l++;
                }

                ans = max(ans, r - l + 1);
            }

            r++;
        }

        return ans;
    }
};