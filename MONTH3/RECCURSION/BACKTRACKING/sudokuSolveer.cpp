#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
{

    // Row-Wise(Horizontal) Exist hai ya nhi
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit)
        {
            return false;
        }
    }

    // col-Wise(Vertical) Exist hai ya nhi
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == digit)
        {
            return false;
        }
    }

    // Grid wise check
    // StartRow and StartCol Of gird
    int startrow = (row / 3) * 3;
    int startcol = (col / 3) * 3;

    for (int i = startrow; i <= startrow + 2; i++)
    {
        for (int j = startcol; j <= startcol + 2; j++)
        {
            if (board[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true;
}
bool sudokuSolver(vector<vector<char>> &board, int row, int col)
{
    // LETS SOLVE IT BY ROWWISE

    // base case
    if (row == 9)
    {
        return true;
    }

    // ✅ Calculate next cell safely
    int nextrow = row;
    int nextcol = col + 1;
    if (nextcol == 9)
    {
        nextcol = 0;
        nextrow = row + 1;
    }

    // IF PLACE IS NOT VACANT
    if (board[row][col] != '.')
    {
        return sudokuSolver(board, nextrow, nextcol);
    }

    // PLACE THE CORRECT DIGIT

    for (char i = '1'; i <= '9'; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i; // Safe Place the digit

            if (sudokuSolver(board, nextrow, nextcol)) // Check for next row and col
                return true;

            board[row][col] = '.'; // BackTrack
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (sudokuSolver(board, 0, 0))
    {
        for (const auto &row : board)
        {
            for (const auto &col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Can not solved";
    }
    return 0;
}