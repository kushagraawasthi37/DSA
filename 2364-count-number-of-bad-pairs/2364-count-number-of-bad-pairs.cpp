class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        long long total = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            nums[i]=(i - nums[i]);
        }

        for(int i =nums.size()-1;i>=0;i--){
            ans+= (total-m[nums[i]]);
            total++;
            m[nums[i]]++;
        }

        return ans;
    }
};