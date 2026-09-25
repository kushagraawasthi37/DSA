class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if (m.find(nums[r]) != m.end())
                return true;
            m[nums[r]]++;

            if (r - l >= k) {
                m[nums[l]]--;
                if (m[nums[l]] <= 0)
                    m.erase(nums[l]);
                l++;
            }

            r++;
        }

        return false;
    }
};