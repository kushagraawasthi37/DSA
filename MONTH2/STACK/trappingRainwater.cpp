#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int trappingRainwaterBet(vector<int> &vec)
{
    // TC->O(N)
    // SC->O(N)

    //  TWO ARRAY USE
    int n = vec.size();
    vector<int> rightMax(n, 0);
    vector<int> leftMax(n, 0);
    leftMax[0] = vec[0];
    rightMax[n - 1] = vec[n - 1];

    // CALCULATION OF RIGHT MAX
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], vec[i]);
    }

    // CALCULATION OF LEFT MAX
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], vec[i]);
    }

    // CALCULATION OF ANSWER
    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        ans1 += min(leftMax[i], rightMax[i]) - vec[i];
    }

    return ans1;
}
int trappingRainwaterOpti(vector<int> &vec)
{
    // TC->O(N)
    // SC->O(1)
    //  TWO POINTER APPROACH

    int n = vec.size();
    int ans = 0;
    int l = 0;
    int r = n - 1;
    int lmax = INT_MIN;
    int rmax = INT_MIN;

    while (l < r)
    {
        lmax = max(lmax, vec[l]);
        rmax = max(rmax, vec[r]);

        // WATER TAP IS ALWAYS DECIDED BY THE VALUE WHICH IS MINIMUM
        if (lmax < rmax)
        {
            ans += (lmax - vec[l]);
            l++;
        }
        else
        {
            ans += (rmax - vec[r]);
            r--;
        }
    }
    return ans;
}
int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trappingRainwaterBet(height) << endl;
    cout << trappingRainwaterOpti(height) << endl;
    return 0;
}