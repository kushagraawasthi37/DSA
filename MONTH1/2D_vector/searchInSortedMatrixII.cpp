#include <bits/stdc++.h>
using namespace std;
bool searchIn2DMatrixII(vector<vector<int>> &mat, int target)
{
    // Matrix is sorted also row-wise and column-wise both
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = n - 1;
    // int mid=s+(e-s)/2;
    while (r < m && c>=0)
    {
        if (mat[r][c] == target)
        {
            return true;
        }
        else if (mat[r][c] < target)
        {
            r++;
        }
        else if (mat[r][c] > target)
        {
            c--;
        }
    }

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

    cout << searchIn2DMatrixII(matrix, target);
    return 0;
}