#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<bool>> &visited, int i, int j, vector<vector<char>> &grid)
    {
        if (i >= visited.size() || i < 0 || j < 0 || j >= visited[0].size() || grid[i][j] == '0' || visited[i][j] == true)
            return;
        visited[i][j] = true;

        dfs(visited, i - 1, j, grid);
        dfs(visited, i - 1, j - 1, grid);
        dfs(visited, i - 1, j + 1, grid);
        dfs(visited, i + 1, j, grid);
        dfs(visited, i + 1, j - 1, grid);
        dfs(visited, i + 1, j + 1, grid);
        dfs(visited, i, j - 1, grid);
        dfs(visited, i, j + 1, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    cnt++;
                    dfs(visited, i, j, grid);
                }
            }
        }

        return cnt;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '0'},
        {'1', '1', '1', '0', '1'},
        {'0', '0', '0', '1', '1'}};

    // Creating an instance of Solution class
    Solution sol;

    /* Function call to find the
    number of islands in given grid */
    int ans = sol.numIslands(grid);

    cout << "The total islands in given grids are: " << ans << endl;

    return 0;
}
