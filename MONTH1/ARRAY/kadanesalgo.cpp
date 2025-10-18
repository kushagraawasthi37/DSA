#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// KADANE algorithm-->MOST OPTIMISED ALGORITHM FOR MAX SUBARRAY SUM

int kadanesAlgo(int arr[], int n)
{
    int curSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];
        // Update maximum sum
        maxSum = max(curSum, maxSum);

        // Check for negative number
        if (curSum < 0)
        {
            curSum = 0;
        }
    }

    return maxSum;
}

int main()
{

    // Brute force approach
    int n = 7;
    int maxSum = INT8_MIN;
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    for (int s = 0; s < n; s++)
    {
        int curSum = 0;
        for (int e = s; e < n; e++)
        {
            curSum += arr[e];
            maxSum = max(curSum, maxSum);
        }
    }

    cout << "MaxSum by Brute Force " << maxSum << endl;

    cout << "Max sum by kadane algorithm " << kadanesAlgo(arr, 7);

    return 0;
}