#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 1)
        return 0;

    sort(arr.begin(), arr.end());

    int ans = arr[n - 1] - arr[0]; // initial difference

    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    for (int i = 1; i < n; i++)
    {
        int minH = min(smallest, arr[i] - k);
        int maxH = max(largest, arr[i - 1] + k);

        if (minH < 0)
            continue; // skip invalid case

        ans = min(ans, maxH - minH);
    }

    return ans;
}


int main()
{
    vector<int> arr = {1, 15, 10};
    int k = 6;

    int result = getMinDiff(arr, k);
    cout << "Minimum difference after modification: " << result << endl;

    return 0;
}