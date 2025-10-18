#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;

        while (s < e)
        {
            int mid = s + (e - s) / 2;

            // If mid element is greater than rightmost, min must be right
            if (arr[mid] > arr[e])
            {
                s = mid + 1;
            }
            else
            {
                // Otherwise min is at mid or left side
                e = mid;
            }
        }
        return arr[s];
    }
};
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    cout << "Minimum element is: " << sol.findMin(arr) << endl;
    return 0;
}
