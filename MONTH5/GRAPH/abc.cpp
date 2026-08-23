#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> dirc = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    bool isValid(int r, int c, int rows, int cols)
    {
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return false;
        return true;
    }

    int solve(vector<vector<int>> &grid, int rows, int cols, int sr, int sc,
              vector<vector<bool>> &visited)
    {
        queue<pair<int, int>> q;
        int minute = 0;
        bool firstTime = true;

        q.push({sr, sc});
        visited[sr][sc] = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for (auto ele : dirc)
            {
                int newRow = x + ele[0];
                int newCol = y + ele[1];

                if (isValid(newRow, newCol, rows, cols) &&
                    !visited[newRow][newCol] && grid[newRow][newCol] == 1)
                {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                    if (firstTime)
                    {
                        minute++;
                        firstTime = false;
                    }
                }
            }

            firstTime = true;
        }

        return minute;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 2)
                {
                    ans += solve(grid, m, n, i, j, visited);
                }
            }
        }

        for (auto row : grid)
        {
            for (auto ele : row)
                cout << ele << " ";
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, { 1, 1,0}, {0,1, 1}};
    Solution s;
    cout << s.orangesRotting(grid) << endl;
}