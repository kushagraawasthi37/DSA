#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxCol(vector<vector<int>> &matrix)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        int colSum = 0;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            colSum += matrix[j][i];
        }

        maxSum = max(colSum, maxSum);
    }

    return maxSum;
}
int main()
{
    // Initialisation of 2D vector
    vector<vector<int>> matrix1(3/*rows*/, vector<int>(3)/*column*/) ;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Same as 2D array
    //  Dynamic size
    // rows=mat.size()
    // column= 1 row mai kitne column hai
    //  col=mat[i].size();

    cout << maxCol(matrix);

    return 0;
}