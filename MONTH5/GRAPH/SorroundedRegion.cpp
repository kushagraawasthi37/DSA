#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<int> dRow = {-1, 0, 0, 1};
        vector<int> dCol = {0, -1, 1, 0};

        // Push boundary cells safely
        for (int i = 0; i < n; i++) {
            // Left boundary
            if (mat[i][0] == 'O' && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            // Right boundary
            if (mat[i][m - 1] == 'O' && !visited[i][m - 1]) {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        for (int j = 0; j < m; j++) {
            // Top boundary
            if (mat[0][j] == 'O' && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = 1;
            }
            // Bottom boundary
            if (mat[n - 1][j] == 'O'&& !visited[n - 1][j]) {
                q.push({n - 1, j});
                visited[n - 1][j] = 1;
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;

            for (int i = 0; i <= 3; i++) {
                int row = x + dRow[i];
                int col = y + dCol[i];

                if (row < n && row >= 0 && col < m && col >= 0 &&
                    visited[row][col] == 0 && mat[row][col] != 'X') {
                    visited[row][col] = 1;
                    q.push({row, col});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ( mat[i][j] != 'X'&&visited[i][j] == 0 ) {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};


int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
	};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to replace 
    surrounded 'O's with 'X's */
    vector<vector<char>> ans = sol.fill(mat);
    
    int n = ans.size();
    int m = ans[0].size();
    
    // Output
    cout << "The updated matrix is: " << endl;
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}