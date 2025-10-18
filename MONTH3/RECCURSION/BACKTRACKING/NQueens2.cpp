#include <bits/stdc++.h>
using namespace std;
// N Queen in n rows
// safe position

bool isSafe(vector<string> &board, int row, int col, int n)
{

    // Horizontal safe
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }
    // Vertical safe
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Diagnol Safe

    // Left Diagonol
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // Right Diagonol
    for (int i = row, j = col; i >= 0 && j < n; j++, i--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {

            board[row][col] = 'Q';

            // RECCURSIVE CALL
            nQueen(board, row + 1, n, ans);

            // BACKTRACKING
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueen(board, 0, n, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueen(4);

    // No Of valid answer
    cout << ans.size() << endl;
    return 0;
}