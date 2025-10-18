#include <bits/stdc++.h>
using namespace std;

int kthLargestSumSubarray(vector<int> &arr, int k)
{
    // Appraoch using the Heap

    //     Time Complexity: O(n² log k)

    // Space Complexity: O(k)

    priority_queue<int, vector<int>, greater<int>> minheap;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // Same logic jaisa kth Largest element mai tha
            sum += arr[j];

            if (minheap.size() < k)
            {
                minheap.push(sum);
            }
            else
            {
                if (sum > minheap.top())
                {
                    minheap.pop();
                    minheap.push(sum);
                }
            }
        }
    }
    return minheap.top();
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    cout << k << "th Largest SubArray sum is " << kthLargestSumSubarray(arr, k);
    return 0;
}