#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;

    // if there are no arr, return empty result.
    if (arr.size() == 0)
    {
        return ans;
    }

    // sorting arr based on their starting points.
    sort(arr.begin(), arr.end());

    int sttime = arr[0][0]; // initialize left end of first interval
    int endtime = arr[0][1]; // initialize right end of first interval

    // iterating over arr starting from 1
    for (int i = 1; i < arr.size(); i++)
    {
        // if current interval overlaps with the previous interval
        if (arr[i][0] <= endtime)
            endtime = max(endtime, arr[i][1]); // update right end

        // if current interval does not overlap with the previous interval
        else
        {
            // add the previous interval to result
            ans.push_back({sttime, endtime});

            // update left and right end for the current interval
            sttime = arr[i][0];
            endtime = arr[i][1];
        }
    }

    // add the last interval to result
    ans.push_back({sttime, endtime});

    // return the merged arr
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = mergeIntervals(arr);

    cout << "Merged Intervals: ";
    for (auto &interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}
