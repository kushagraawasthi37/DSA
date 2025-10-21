#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to get the minimum
     bit flips to convert number */
    int minBitsFlip(int start, int goal)
    {

        /* Variable to store bits that
        are different in both numbers */
        int num = start ^ goal;

        /* Variable to count
        number of set bits */
        int count = 0;

        for (int i = 0; i < 32; i++)
        {
            /* Update count if the
            rightmost bit is set */
            count += (num & 1);

            /* Shift the number every
            time by 1 place */
            num = num >> 1;
        }
        return count;
    }
};

int main()
{
    int start = 10, goal = 7;

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to get the minimum
     bit flips to convert number */
    int ans = sol.minBitsFlip(start, goal);

    cout << "The minimum bit flips to convert number is: " << ans;

    return 0;
}
