#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Just find element at rth row and cth column (1-basedd indexing)
    int pascalTriangleI(int r, int c)
    {
        int ans = 1;
        for (int i = 1; i < c; i++)
        {
            ans *= (r - i);
            ans /= i;
        }
        return ans;
    }

    // Complete rth row
    vector<int> pascalTriangleII(int row)
    {

        long long ans = 1;
        vector<int> ansRow;

        /// Inserting the 1st element
        ansRow.push_back(1);

        // Calculate the rest of the elements
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow; // Return the computed row
    }

    // Complete Pascal triangle
    vector<vector<int>> pascalTriangleIII(int n)
    {
        vector<vector<int>> result(n);
        n = n - 1;

        for (int i = 0; i <= n; i++)
        {
            vector<int> rowAns(i);

            for (int j = 0; j <= i; j++)
            {
                // Edge case handeling
                if (j == 0 || j == i)
                {
                    result[i].push_back(1);
                    // rowAns.push_back(1);
                }

                else if (i - 1 >= 0 && j - 1 >= 0)
                {
                    int ele = result[i - 1][j - 1] + result[i - 1][j];

                    result[i].push_back(ele);
                    // rowAns.push_back(ele);
                }
            }
            // result.push_back(rowAns);
        }
        return result;
    }
};

int main()
{

    return 0;
}