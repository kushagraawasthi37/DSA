#include <bits/stdc++.h>
using namespace std;

bool pairInSortedRotated(vector<int> &arr, int target)
{
    int n = arr.size();

    // Find the pivot element
    int pvt;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
        {
            pvt = i;
            break;
        }

    // l is now index of smallest element
    int l = (pvt + 1) % n;

    // r is now index of largest element
    int r = pvt;

    // Keep moving either l or r till they meet
    while (l != r)
    {

        // If we find a pair with sum target, return true
        if (arr[l] + arr[r] == target)
            return true;

        // If current pair sum is less, move to higher sum
        if (arr[l] + arr[r] < target)
            l = (l + 1) % n;

        // Move to lower sum
        else
            r = (r - 1 + n) % n;
    }
    return false;
}
int main()
{
    return 0;
}