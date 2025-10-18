#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the median of two sorted arrays.
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1 > n2)
        {
            return median(arr2, arr1);
        }

        int s = 0;    // array 1 se Minimum elements   0 le skta hu
        int end = n1; // array 1 se Maximum elements   n1 le skta hu

        // Number of element on the left of median of Final sorted array
        int left = (n1 + n2 + 1) / 2; // Valid for both odd and even array
        while (s <= end)
        {
            int mid1 = s + (end - s) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (double)((double)(max(l1, l2) + min(r1, r2)) / 2.0);
                }
                // Odd case
                else
                {
                    return (double)max(l1, l2);
                }
            }

            else if (l1 < r2)
            {
                // Eliminate the left half of arr1
                s = mid1 + 1;
            }
            else
            {
                // Eliminate the right half of arr1
                end = mid1 - 1;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}