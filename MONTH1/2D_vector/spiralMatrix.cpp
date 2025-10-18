#include <bits/stdc++.h>
using namespace std;
void spiralMatrixInput(int mat[][4], int col, int row)
{
    int left = 0;
    int right = col - 1; // 3
    int top = 0;
    int bottom = row - 1; // 2
    int direc = 0;

    while (left <= right && top <= bottom)
    {
        // Right traverse
        if (direc == 0)
        {
            for (int i = left; i <= right; i++)
            {
                cin >> mat[top][i];
            }
            top++;
        }

        // Down Traverse
        else if (direc == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                cin >> mat[i][right];
            }
            right--;
        }
        
        // Left Traverse
        else if (direc == 2)
        {
            for (int i = right; i >= left; i--)
            {
                cin >> mat[bottom][i];
            }
            bottom--;
        }
        else
        {
            for (int i = bottom; i >= top; i--)
            {
                cin >> mat[i][left];
            }
            left++;
        }
        direc = (direc + 1) % 4;
    }
}
void spiralMatrixPrint(int mat[][4], int col, int row)
{
    int left = 0;
    int right = col - 1; // 3
    int top = 0;
    int bottom = row - 1; // 2
    int direc = 0;

    while (left <= right && top <= bottom)
    {
        // Right traverse
        if (direc == 0)
        {
            for (int i = left; i <= right; i++)
            {
                cout << mat[top][i] << " ";
            }
            top++;
        }

        // Down Traverse
        else if (direc == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                cout << mat[i][right] << " ";
            }
            right--;
        }
        // Left Traverse
        else if (direc == 2)
        {
            for (int i = right; i >= left; i--)
            {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }
        else
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
            left++;
        }
        direc = (direc + 1) % 4;
    }
}
int main()
{
    int mat[3][4];

    spiralMatrixInput(mat, 4, 3);
    spiralMatrixPrint(mat, 4, 3);
    return 0;
}