#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIdx(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (i <= high - 1 && nums[i] <= pivot)
            {
                i++;
            }
            while (j >= low + 1 && nums[j] > pivot)
            {
                j--;
            }

            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void qs(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pivot = pivotIdx(nums, low, high);

            qs(nums, low, pivot - 1);
            qs(nums, pivot + 1, high);
        }
    }
    vector<int> quickSort(vector<int> &nums)
    {
        qs(nums, 0, nums.size() - 1);

        return nums;
    }
};
