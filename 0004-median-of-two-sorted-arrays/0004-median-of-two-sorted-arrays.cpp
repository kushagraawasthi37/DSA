class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int s = 0;
        int e = n1;

        int medianIdx = (n1 + n2 + 1) / 2;
        while (s <= e) {
            int mid1 = (s + e) >> 1;
            int mid2 = medianIdx - mid1;

            int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            int r1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) & 1)
                    return max(l1, l2);

                else
                    return 1.0 * (max(l1, l2) + min(r1, r2)) / 2;
            }

            if (l1 >= r2) {
                e = mid1 - 1;
            } else
                s = mid1 + 1;
        }

        return -1;
    }
};