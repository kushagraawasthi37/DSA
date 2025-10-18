#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int resultRow = -1;

        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            bool flag = false;
            int mid = s + (e - s) / 2;
            for (int i = 0; i < m; i++)
            {
                if (mat[i][mid] == 1)
                {
                    resultRow = i;
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return resultRow;
    }
};

int main()
{
    return 0;
}