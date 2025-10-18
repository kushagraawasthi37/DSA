#include <bits/stdc++.h>
using namespace std;

// 3Sum brute force TC->O(n^3*log(unique Triplet))
// 3Sum brute force SC->O(unique Triplet)

vector<vector<int>> threeSum(vector<int> &v, int tar)
{
    int n = v.size();
    set<vector<int>> s;
    vector<vector<int>> ans;

    // for Unique Triplet in answer
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == tar)
                {
                    vector<int> temp = {v[i], v[j], v[k]};


                    // Check triplet already exist or not
                    if (s.find(temp) == s.end())
                    {
                        s.insert(temp);
                        ans.push_back(temp);
                    }
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> hashThreeSum(vector<int> &v, int target)
{
    int n = v.size();
    set<vector<int>> uniqueTriplets;

    // Loop through each element to find potential triplets
    for (int i = 0; i < n; i++)
    {
        int remainingTarget = target - v[i]; // Remaining target after using v[i]
        set<int> s;

        for (int j = i + 1; j < n; j++)
        {
            int third = remainingTarget - v[j]; // Calculate third element needed

            // Check if the third element already exists in the set
            if (s.find(third) != s.end())
            {
                // Found a valid triplet, sort and insert it
                vector<int> trip = {v[i], v[j], third};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip); // Insert into set to ensure uniqueness
            }
            s.insert(v[j]); // Insert the current element into the set for future checks
        }
    }

    // copy unique triplet set into answer
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

vector<vector<int>> threeSumOptimalApproach(vector<int> vec, int tar)
{
    vector<vector<int>> ans;
    sort(vec.begin(), vec.end());

    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        // Optimise condition 1
        if (i > 0 && vec[i] == vec[i - 1]) // Duplicate elements Skip
        {
            continue;
        }

        int p = i + 1, q = n - 1;
        while (p < q)
        {
            int sum = vec[i] + vec[q] + vec[p];
            if (sum < tar)
            {
                p++;
            }
            if (sum > tar)
            {
                q--;
            }
            if (sum == tar)
            {
                ans.push_back({vec[i], vec[p], vec[q]});
                p++;
                q--;
                // Optimise condition 2
                while (p < q && vec[p] == vec[p - 1])
                {
                    p++; // Duplicate element skip
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {5,4,1,3,6,3,1};
    int tar = -1;
    vector<vector<int>> ans;
    vector<vector<int>> ans1;
    vector<vector<int>> ans2;
    ans = threeSum(v, 0);
    ans1 = hashThreeSum(v, 0);
    ans2 = threeSumOptimalApproach(v, 0);

    cout << "Three Sum Brute force approach " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Three Sum Better approach by Hashing " << endl;
    for (int i = 0; i < ans1.size(); i++)
    {
        for (int j = 0; j < ans1[0].size(); j++)
        {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Optimal Solution of three sum " << endl;
    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2[0].size(); j++)
        {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
