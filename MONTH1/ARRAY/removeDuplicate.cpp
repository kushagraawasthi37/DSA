#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int idx = 0;

    if (nums.empty())
        return 0;

    for (int i = 0; i < n; i++)
    {
        // Remove duplicate
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        // Assigning
        nums[idx++] = nums[i];
    }
    return idx;
}
int main()
{
    vector<int> v = {1, 2, 2, 3};

    cout << removeDuplicates(v);
    return 0;
}