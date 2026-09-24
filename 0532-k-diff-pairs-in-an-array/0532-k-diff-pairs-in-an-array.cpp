class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long total = 0;
        long long ans = 0;

        for (auto ele : nums) {
            m[ele]++;
        }
        if (k == 0) {
            for (auto it : m) {
                if (it.second > 1)
                    ans++;
            }

            return ans;
        }

        for (auto& [x, freq] : m) {
            if (m.find(x + k) != m.end())
                ans++;
        }
        return ans;
    }
};