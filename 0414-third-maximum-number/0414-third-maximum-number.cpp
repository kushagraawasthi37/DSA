class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long max1 = -1e10;
        long long max2 = -1e10;
        long long max3 = -1e10;

        for (auto ele : nums) {
            if (ele > max1) {
                max3 = max2;
                max2 = max1;
                max1 = ele;
            }
            if (ele > max2 && ele != max1) {
                max3 = max2;
                max2 = ele;
            }
            if (ele > max3 && max1 != ele && ele != max2) {
                max3 = ele;
            }
        }

        return max3 != -1e10 ? max3 : max1;
    }
};