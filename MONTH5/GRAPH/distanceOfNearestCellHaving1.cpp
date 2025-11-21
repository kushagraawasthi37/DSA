#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m] = {0};
        vector<vector<int>>  dist(n,vector<int>(m));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                   
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }else{
                     visited[i][j] = 0; 
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first.first;
            int y = front.first.second;
            int distance = front.second;
            dist[x][y] = distance;
            int dRow[] = {-1, 0, 0, 1};
            int dCol[] = {0, -1, 1, 0};

            for (int i = 0; i < 4; i++) {
                int row = x + dRow[i];
                int col = y + dCol[i];

                if (row < n && row >= 0 && col >= 0 && col < m &&
                    visited[row][col] == 0) {
                    visited[row][col] = 1;
                    q.push({{row, col}, distance + 1});
                }
            }
        }
            return dist;
    }
};


int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0}, 
        {1, 1, 0, 0}, 
        {0, 0, 1, 1}
	};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the distance of the 
    nearest 1 in the grid for each cell. */
    vector<vector<int>> ans = sol.nearest(grid);
    
    int n = ans.size();
    int m = ans[0].size();
    
    // Output
    cout << "The distance of the nearest 1 in the grid for each cell is: " << endl;
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}