class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> m;
        m[0]++;
        int ans = 0;

        for (auto it : nums) {
            sum += it;
            int rem = ((sum % k) + k) % k;
            ans += m[rem];
            m[rem]++;
        }

        return ans;
    }
};