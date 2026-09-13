class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;

        deque<int> increasing;
        deque<int> decreasing;
        int l = 0;
        int r = 0;

        while (r < nums.size()) {
            while (!increasing.empty() && increasing.back() > nums[r])
                increasing.pop_back();
            increasing.push_back(nums[r]);

            while (!decreasing.empty() && decreasing.back() < nums[r])
                decreasing.pop_back();
            decreasing.push_back(nums[r]);

            while (abs(decreasing.front() - increasing.front()) > limit) {
                if (decreasing.front() == nums[l])
                    decreasing.pop_front();
                if (increasing.front() == nums[l])
                    increasing.pop_front();

                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};