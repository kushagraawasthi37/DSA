class Solution {
private:
    bool isValid(vector<int>& nums, int mid, int k) {
        int curr = 0;
        int currArr = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (curr + nums[i] > mid) {
                currArr++;
                curr = nums[i];
                if (currArr > k)
                    return false;
            } else {
                curr = curr + nums[i];
            }
        }

        return currArr <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);

        int ans = e;

        while (s <= e) {
            int mid = (s + ((e - s) >> 1));

            cout << s << " " << e << " " << mid << endl;

            if (isValid(nums, mid, k)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }

        return ans;
    }
};