class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= 0 || nums[i] > nums.size()) {
                i++;
            } else {
                int realIdx = nums[i] - 1;

                if (nums[realIdx] == nums[i])
                    i++;

                else if (nums[realIdx] < 0) {
                    nums[realIdx] = nums[i];
                    nums[i] = -1;
                    i++;
                } else {
                    nums[i] = nums[realIdx];
                    nums[realIdx] = realIdx + 1;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i])
                return i + 1;
        }

        return nums.size() + 1;
    }
};