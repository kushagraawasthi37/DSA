#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Helper function to find the index of the row
    with the maximum element in a given column*/
    int maxElement(vector<vector<int>> &arr, int col)
    {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        /* Iterate through each row to find the
        maximum element in the specified column*/
        for (int i = 0; i < n; i++)
        {
            if (arr[i][col] > max_val)
            {
                max_val = arr[i][col];
                index = i;
            }
        }
        // Return the index
        return index;
    }

    /* Function to find a peak element in
     the 2D matrix using binary search */
    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        /* Initialize the lower bound for
        and upper bound for binary search */
        int low = 0;
        int high = m - 1;

        // Perform binary search on columns
        while (low <= high)
        {
            int mid = (low + high) / 2;

            /* Find the index of the row with the
            maximum element in the middle column*/
            int row = maxElement(arr, mid);

            /* Determine the elements to left and
            right of middle element in the found row */
            int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;

            /* Check if the middle element
             is greater than its neighbors */
            if (arr[row][mid] > left && arr[row][mid] > right)
            {
                return {row, mid};
            }
            else if (left > arr[row][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Return {-1, -1} if no peak element is found
        return {-1, -1};
    }
};
int main()
{
    return 0;
}