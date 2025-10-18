#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;

        // r = 1 se n-2 tak kyunki peak kabhi 0 ya last index pe nahi hoga
        for (int r = 1; r < n - 1; r++)
        {
            // check karo ki r ek peak hai
            if (arr[r - 1] < arr[r] && arr[r] > arr[r + 1])
            {
                int l = r - 1;
                int e = r + 1;

                // left side extend karo jab tak strictly increasing hai
                while (l > 0 && arr[l] > arr[l - 1])
                {
                    l--;
                }

                // right side extend karo jab tak strictly decreasing hai
                while (e < n - 1 && arr[e] > arr[e + 1])
                {
                    e++;
                }

                // mountain ka length update karo
                ans = max(ans, e - l + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {2, 1, 4, 7, 3, 2, 5};
    cout << "Test 1: " << sol.longestMountain(arr1) << endl; // Expected 5

    vector<int> arr2 = {2, 2, 2};
    cout << "Test 2: " << sol.longestMountain(arr2) << endl; // Expected 0 (no mountain)

    vector<int> arr3 = {0, 2, 2, 2, 1, 0};
    cout << "Test 3: " << sol.longestMountain(arr3) << endl; // Expected 0 (flat part)

    vector<int> arr4 = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    cout << "Test 4: " << sol.longestMountain(arr4) << endl; // Expected 9 (whole array)

    vector<int> arr5 = {1, 3, 2};
    cout << "Test 5: " << sol.longestMountain(arr5) << endl; // Expected 3 (small mountain)

    return 0;
}
