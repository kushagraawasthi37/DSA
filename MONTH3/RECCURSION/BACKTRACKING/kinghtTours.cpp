#include <bits/stdc++.h>
using namespace std;
bool isValidKnightTour(vector<vector<int>> &grid, int r, int c, int n, int expVal)
{
    // TC->O(8^n*n);
    // SC->O(n*n);
    if ((r < 0 || c < 0) || r >= n || c >= n || (grid[r][c] != expVal))
    {
        return false;
    }

    if (expVal == ((n * n) - 1))
    {
        return true;
    }

    // ALL POSSIBLE VALUE OF KNIGHT MOVES OPTION
    bool ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8;
    ans1 = isValidKnightTour(grid, r - 2, c + 1, n, expVal + 1);
    ans3 = isValidKnightTour(grid, r + 1, c + 2, n, expVal + 1);
    ans2 = isValidKnightTour(grid, r - 1, c + 2, n, expVal + 1);
    ans4 = isValidKnightTour(grid, r + 2, c + 1, n, expVal + 1);
    ans5 = isValidKnightTour(grid, r + 2, c - 1, n, expVal + 1);
    ans6 = isValidKnightTour(grid, r + 1, c - 2, n, expVal + 1);
    ans7 = isValidKnightTour(grid, r - 1, c - 2, n, expVal + 1);
    ans8 = isValidKnightTour(grid, r - 2, c - 1, n, expVal + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

int main()
{
    int n = 5;
    vector<vector<int>> grid = {{0, 5, 14, 9, 20},
                                {13, 8, 19, 4, 15},
                                {18, 1, 6, 21, 10},
                                {7, 12, 23, 16, 3},
                                {24, 17, 2, 11, 22}};

    // Find the starting position where value is 0
    int startR = -1, startC = -1;
    for (int i = 0; i < n && startR == -1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                startR = i;
                startC = j;
                break;
            }
        }
    }

    if (startR == -1 || startC == -1)
    {
        cout << "No starting point found (0 not in grid)." << endl;
        return 1;
    }

    if (isValidKnightTour(grid, startR, startC, n, 0))
    {
        cout << "Valid Knight's Tour" << endl;
    }
    else
    {
        cout << "Invalid Knight's Tour" << endl;
    }

    return 0;
}
