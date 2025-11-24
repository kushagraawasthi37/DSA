#include <bits/stdc++.h>
using namespace std;
class Solution {
   private:
    void solveDFS(vector<vector<int>> &grid, vector<vector<int>> &visited,
                  vector<pair<int, int>> &path, int x, int y, int &base_row,
                  int &base_col) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
            visited[x][y] || grid[x][y] == 0)
            return;

        visited[x][y] = 1;
        path.push_back({x- base_row, y - base_col});
        solveDFS(grid, visited, path, x - 1, y,base_row,base_col);
        solveDFS(grid, visited, path, x, y - 1,base_row,base_col);
        solveDFS(grid, visited, path, x, y + 1,base_row,base_col);
        solveDFS(grid, visited, path, x + 1, y,base_row,base_col);
    }

   public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> visited(n, vector<int>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    vector<pair<int, int>> path;
                    solveDFS(grid, visited, path, i, j, i, j);
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};


int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1}, 
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
	};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function to count the count of
     distinct islands in the given grid */
    int ans = sol.countDistinctIslands(grid);
    
    // Output
    cout << "The count of distinct islands in the given grid is: " << ans << endl;
    
    
    return 0;
}