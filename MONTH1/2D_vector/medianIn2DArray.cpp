#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool isValidMedian(vector<vector<int>> mat, int medianEle, int expMedian)
    {
        int cnt = 0;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++)
        {
            int s = 0;
            int e = cols - 1;

            // Median ko include krke use left ke element count karo
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (mat[i][mid] > expMedian)
                {
                    e = mid - 1;
                }
                else
                {
                    cnt += mid - s + 1;
                    s = mid + 1;
                }
            }
        }
        // Kya ye count valid hai ya nahi
        return cnt >= medianEle;
    }

public:
    int findMedian(vector<vector<int>> &mat)
    {
        if (mat.empty() || mat[0].empty())
            return -1; // or handle accordingly
        int rows = mat.size();
        int cols = mat[0].size();

        int totalele = rows * cols;
        // Median ko include karke kitne element uske left mai honge
        int medianEle = (totalele / 2) + 1;

        int s = INT_MAX;
        int e = INT_MIN;
        for (int i = 0; i < rows; i++)
        {
            s = min(s, mat[i][0]);
            e = max(e, mat[i][cols - 1]);
        }

        int ans;

        // Median ki range start(smallest element) se end(largest element) tak hi ho skti hai

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            // Agar mid ke left mai median ke left mai jitne element chahite utne hai to mid ek potential answer ho skta hai
            if (isValidMedian(mat, medianEle, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}
