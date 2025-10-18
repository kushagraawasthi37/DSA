#include <bits/stdc++.h>
using namespace std;
bool searchInRow(vector<vector<int>> &matrix, int tar, int resRow)
{
    int st = 0;
    int end = matrix[0].size() - 1;

    // TC ->O(logm)
    while (st <= end)
    {
        int mid1 = st + (end - st) / 2;
        if (matrix[resRow][mid1] > tar)
        {
            end = mid1 - 1;
        }
        else if (matrix[resRow][mid1] < tar)
        {
            st = mid1 + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}
bool searchIn2DMatrix(vector<vector<int>> &matrix, int tar)
{
    // Search Correct row using binary search
    // Search in correct row using binary search

    int m = matrix.size();    // no of rows
    int n = matrix[0].size(); // No of column
    int startRow = 0;
    int endRow = m - 1;
    int resRow = -1;

    // TC ->O(logn)
    // BS On total row;
    while (startRow <= endRow)
    {
        int mid = startRow + (endRow - startRow) / 2;

        if (matrix[mid][0] > tar)
        {
            // Upar jana hai
            endRow = mid - 1;
        }
        else if (matrix[mid][n - 1] < tar)
        {
            // Down jana hai
            startRow = mid + 1;
        }
        else
        {
            return searchInRow(matrix, tar, mid);
        }
    }

    // Total TC=> O(log m*n)
    return false;
}
int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));
    int target = 5;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << searchIn2DMatrix(matrix, target);
    return 0;
}