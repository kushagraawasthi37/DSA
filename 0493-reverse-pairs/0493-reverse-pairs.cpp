class Solution {
private:
    int merge(vector<int>& nums, int s, int mid, int e) {
        int count = 0;

        // ✅ Step 1: Count reverse pairs
        int j = mid + 1;
        for (int i = s; i <= mid; i++) {
            while (j <= e && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // ✅ Step 2: Normal merge
        vector<int> temp;
        int i = s;
        j = mid + 1;

        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= e) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++) {
            nums[s + k] = temp[k];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e) return 0;

        int mid = (s + e) / 2;

        int left = mergeSort(nums, s, mid);
        int right = mergeSort(nums, mid + 1, e);

        int curr = merge(nums, s, mid, e);

        return left + right + curr;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};