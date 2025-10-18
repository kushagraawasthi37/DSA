#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool linearSeearch(int matrix[][3], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (key == matrix[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

int maxSum(int mat[][3], int row, int col)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int curSum = 0;
        for (int j = 0; j < col; j++)
        {
            curSum += mat[i][j];
        }

        maxSum = max(curSum, maxSum);
    }
    return maxSum;
}
int diagnolSum(int mat[][3], int n)
{
    // TC->O(n^2);
    int digSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Primary Diagonal
            if (i == j)
            {
                digSum += mat[i][j];
            }

            // Secondary Diagonal
            if (i + j == n - 1)
            {
                digSum += mat[i][j];
            }

            // remove middle element
            if (n % 2 != 0 && i == n / 2 && j == n / 2)
            {
                digSum -= mat[i][j];
            }
        }
    }
    return digSum;
}
int optDiagnolSum(int mat[][3], int n)
// TC->O(n);
{
    int digSum = 0;
    for (int i = 0; i < n; i++)
    {

        // Primary Diagonal
        digSum += mat[i][i];

        // Secondary Diagona
        digSum += mat[i][n - 1 - i];

        // remove middle element
    }

    if (n % 2 != 0)
    {
        digSum -= mat[n / 2][n / 2];
    }
    return digSum;
}

// optimise timeComple

int main()
{

    // Initialisation in 2D array
    int matrix[3 /*row*/][3 /*col*/];
    // Every row in itself a 1D array
    int arr[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};

    // Accesing the element in 2D array
    // cout << arr[1][1] << endl;

    // change value in 2D array
    arr[1][2] = 4;
    // cout << arr[1][2] << endl;

    // Loops in 2D array

    // Input 2D array Element
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // OutPut 2D array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // cout << matrix[i][j] << " ";
        }
        // cout << endl;
    }

    // 2D array in memory
    //  1.Row major  first row element then 2nd row in single row in memory
    // 2.Column major->first column then 2nd collumn then so on in single row

    // Linear Search in 2D array
    cout << linearSeearch(matrix, 3, 3, 10) << endl;
    cout << "Row with Maximum Sum " << maxSum(matrix, 3, 3) << endl;
    cout << "Diagnol sum " << diagnolSum(matrix, 3) << endl;
    cout << "Diagnol sum Optimised  " << optDiagnolSum(matrix, 3) << endl;

    return 0;
}