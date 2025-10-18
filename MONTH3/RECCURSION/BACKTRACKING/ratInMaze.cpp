#include <bits/stdc++.h>
using namespace std;

void ratInMaze(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &visited)
{
    int n = maze[0].size();

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    if (row < 0 || col >= n || col < 0 || row >= n || maze[row][col] == 0 || visited[row][col] == true)
    {
        return;
    }

    // maze[row][col] = 0; // Aab rat iss par bhi nahi ja skte but original matrix change ho jayega agar question mai agar bola hai koi dikkat nahi to visited ko remove karke direct ye bhi use kar skte hai

    visited[row][col] = true;

    ratInMaze(maze, row + 1, col, path + "D", ans, visited);
    ratInMaze(maze, row, col - 1, path + "L", ans, visited);
    ratInMaze(maze, row, col + 1, path + "R", ans, visited);
    ratInMaze(maze, row - 1, col, path + "U", ans, visited);

    // maze[row][col] = 1; // Backtrack
    visited[row][col] = false;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1}};

    string path = "";
    int n = maze.size();
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    if (maze[0][0] == 1) // Only run if starting cell is open
        ratInMaze(maze, 0, 0, path, ans, vis);

    if (ans.empty())
    {
        cout << "No path found." << endl;
    }
    else
    {
        for (const auto &path : ans)
            cout << path << endl;
    }

    return 0;
}