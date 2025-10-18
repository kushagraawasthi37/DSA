#include <bits/stdc++.h>
using namespace std;
int subArraySum(vector<int> &vec, int tar)
{
    // TC->O(n^2)
    int n = vec.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += vec[j];
            if (sum == tar)
            {
                count++;
            }
        }
    }
    return count;
}
int optSubArraySum(vector<int> &vec, int tar)
{

    // TC->O(n)
    // SC-> O(n)

    // Prefix Sum approach
    int n = vec.size();
    int count = 0;

    vector<int> prefixSum(n);
    prefixSum[0] = vec[0];

    for (int i = 1; i < n; i++)
    {
        // Formula for calculation of prefix sum
        prefixSum[i] = vec[i-1] + prefixSum[i - 1];
    }

    // 9, 4, 0, 20, 3, 10, 5->Array
    // 9, 13, 13 ,33 ,36 ,46 ,51->Prefix Sum array
    
    unordered_map<int, int> m; // PrefixSum ,frequency
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == tar)
        {
            count++;
        }

        int val = prefixSum[j] - tar;
        if (m.find(val) != m.end())
        {
            // Adding frequency to count
            count += m[val];
        }
        else
        {
            m[prefixSum[j]]++;
        }
    }
    return count;
}
int main()
{
    vector<int> v = {9, 4, 0, 20, 3, 10, 5};
    int tar = 33;
    cout << "Sub Array brute force approach " << subArraySum(v, tar) << endl;
    cout << "Sub Array Optimised approach " << optSubArraySum(v, tar) << endl;
    return 0;
}