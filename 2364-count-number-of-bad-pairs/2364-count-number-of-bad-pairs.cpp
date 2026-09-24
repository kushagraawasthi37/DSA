class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector<int> arr(nums.size(),0);
        unordered_map<int, int> m;
        long long total = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            arr[i]=(i - nums[i]);
        }

        for(int i =nums.size()-1;i>=0;i--){
            // cout<<arr[i]<<" ";
            ans+= (total-m[arr[i]]);
            total++;
            m[arr[i]]++;
        }

        return ans;
    }
};