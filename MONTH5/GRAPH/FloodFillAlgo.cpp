#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<vector<int>> &nums, vector<vector<bool>> &visited, int i,
               int j, int p, int newColor)
    {
        if (i < 0 || j < 0 || i >= nums.size() || j >= nums[0].size() ||
            visited[i][j] || nums[i][j] != p)
            return;
        visited[i][j] = true;
        nums[i][j] = newColor;

        solve(nums, visited, i - 1, j, p, newColor);
        solve(nums, visited, i, j - 1, p, newColor);
        solve(nums, visited, i + 1, j, p, newColor);
        solve(nums, visited, i, j + 1, p, newColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        solve(image, visited, sr, sc, image[sr][sc], newColor);

        return image;
    }
};

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int sr = 1, sc = 1;
    int newColor = 2;

    int n = image.size();
    int m = image[0].size();

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to find the
    number of islands in given grid*/
    vector<vector<int>> ans = sol.floodFill(image, sr, sc, newColor);

    cout << "Image after performing flood fill algorithm: \n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}