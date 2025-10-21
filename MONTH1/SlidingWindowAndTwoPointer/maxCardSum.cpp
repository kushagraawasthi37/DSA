#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Simple using sliding window
    int maxScore(vector<int> &cardScore, int k)
    {
        // your code goes here
        int n = cardScore.size();
        int total = 0;
        for (int ele : cardScore)
        {
            total += ele;
        }
        int r = 0;
        int l = 0;
        int sum = 0;
        int miniSum = INT_MAX;
        int winSize = n - k;
        while (r < n)
        {
            sum += cardScore[r];
            winSize--;

            if (winSize < 0)
            {
                sum -= cardScore[l];
                l++;
                winSize++;
            }

            if (winSize == 0)
            {
                miniSum = min(sum, miniSum);
            }
            r++;
        }

        return total - miniSum;
    }

    // Using prefixSum and sliding window
    int maxScorePrefixSum(vector<int> &cardScore, int k)
    {
        // your code goes here

        int leftSum = 0;
        int rightSum = 0;
        int maxSum = INT_MIN;
        int n = cardScore.size();

        for (int i = 0; i < k; i++)
        {
            leftSum += cardScore[i];
            maxSum = leftSum;
        }

        int rightIdx = n - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            leftSum -= cardScore[i];
            rightSum += cardScore[rightIdx];
            rightIdx--;

            maxSum = max(maxSum, rightSum + leftSum);
        }

        return maxSum;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Create an instance of the Solution class
    Solution sol;

    int result = sol.maxScore(nums, 3);

    // Output the maximum score
    cout << "The maximum score is:\n";
    cout << result << endl;

    return 0;
}