class Solution {
private:
    // Using the Binary Search
    int solveBS(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;

        for (int num : nums) {
            if (temp.size() == 0||temp.back()<num)
                temp.push_back(num);
            else {
                int idx =
                    lower_bound(temp.begin(), temp.end(), num) - temp.begin();
                temp[idx] = num;
            }
        }

        return (int)temp.size();
    }

public:
    int lengthOfLIS(vector<int>& nums) { return solveBS(nums); }
};