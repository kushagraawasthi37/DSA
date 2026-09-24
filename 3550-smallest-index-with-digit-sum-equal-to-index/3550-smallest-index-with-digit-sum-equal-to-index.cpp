class Solution {
    int digitSum(int n){
        int ans =0;
        while(n){
            ans+= (n%10);
            n/=10;
        }

        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(digitSum(nums[i])==i) return i;
        }

        return -1;
    }
};