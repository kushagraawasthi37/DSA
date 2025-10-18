#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<vector<char>> &board, string word, bool &ans, int row,
               int col, vector<vector<bool>> &visited)
    {
        int n = board.size();
        int m = board[0].size();
        if (word.length() == 0)
        {
            ans = true;
            return;
        }

        if (row < 0 || row >= n || col < 0 || col >= m ||
            visited[row][col] == true || board[row][col] != word[0])
        {
            return;
        }

        visited[row][col] = true;

        if (board[row][col] == word[0])
        {
            int a = word.length();
            word = word.substr(1, a - 1);
        }
        solve(board, word, ans, row + 1, col, visited);
        solve(board, word, ans, row, col - 1, visited);
        solve(board, word, ans, row - 1, col, visited);
        solve(board, word, ans, row, col + 1, visited);

        visited[row][col] = false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // your code goes here
        bool ans = false;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int row, col;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    row = i;
                    col = j;
                    solve(board, word, ans, row, col, visited);
                    if (ans)
                        return ans;
                }
            }
        }

        return ans;
    }
};

// Main function to test the solution
int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    if (sol.exist(board, word))
    {
        cout << "Word found!" << endl;
    }
    else
    {
        cout << "Word not found!" << endl;
    }

    return 0;
}