#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j])
            return;

        vis[i][j] = true;

        dfs(i - 1, j, grid, vis);
        dfs(i + 1, j, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i, j + 1, grid, vis);
    }

public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // 1. Mark all land reachable from the boundary
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, vis);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid, vis);
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid, vis);
            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid, vis);
        }

        // 2. Count land cells NOT visited = enclaves
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    // Function call to get number of enclaves
    int ans = sol.numberOfEnclaves(grid);

    cout << "The number of enclaves in given grid are: " << ans;
    return 0;
}