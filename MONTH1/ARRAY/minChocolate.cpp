#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinDiff(vector<int> &a, int m)
    {
        // code here
        sort(a.begin(), a.end());
        int diff = INT_MAX;

        for (int i = 0; i + m - 1 < a.size(); i++)
        {
            diff = min(diff, a[i + m - 1] - a[i]);
        }

        return diff;
    }
};
int main()
{
    return 0;
}