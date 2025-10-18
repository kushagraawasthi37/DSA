#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool twoSum(vector<int> &arr, int tar)
{
    // Brute Force sab pair ka sum nikal lo then calculate krlo TC->O(n^2)

    // better approach TC-> O(nlogn)

    // Sort Array
    sort(arr.begin(), arr.end());
    int str = 0;
    int end = arr.size() - 1;

    while (str < end)
    {
        int sum = arr[str] + arr[end];
        if (sum == tar)
        {
            return true;
        }
        if (sum > tar)
        {
            end--;
        }
        if (sum < tar)
        {
            str++;
        }
    }

    return false;
}

pair<int, int> optTwoSum(vector<int> &arr, int tar)
{
    vector<int> ans;
    // Unordered map and set-> insert/find/delete time complexity =O(1)
    unordered_map<int /*key*/, int /*value*/> m;

    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int sec = tar - first;

        // Second element already exist in Map
        if (m.find(sec) != m.end())
        {
            return make_pair(sec,first);
        }

        // Update map
        m[first]++;
    }
}
int main()
{
    vector<int> arr = {2, 7, 11, 15};
    cout << "Two sum Better Complexity " << twoSum(arr, 9) << endl;
    pair<int, int> p = optTwoSum(arr, 9);
    cout << "Two sum optimal complexity \n";
    cout << p.first << " " << p.second << endl;
}