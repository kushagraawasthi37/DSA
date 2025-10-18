#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n1 = a.size();
        int n2 = b.size();

        if (n1 > n2)
        {
            return kthElement(b, a, k);
        }

        int left = k;
        int st = max(0, k - n2); // Minimum element jo array 1 se lene hi padenge (n2 se sab element le liye aab bhi k nahi ho paye to array 1 ke kuch element to lene padenge)
        int end = min(k, n1);    // Maximum element jo array se le skta hu

        while (st <= end)
        {
            int mid1 = st + (end - st) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

            if (l2 <= r1 && l1 <= r2)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                end = mid1 - 1;
            }
            else
            {
                st = mid1 + 1;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}