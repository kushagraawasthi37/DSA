#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // My approach It can be optimised
    int longestConsecutive(vector<int> &nums)
    {
        int maxSequenceCount = 1;
        int cnt = 1;
        int n = nums.size();
        unordered_map<int, int> map;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (map.find(nums[i] - 1) == map.end())
            {
                cnt = 1;
            }
            else
            {
                if (i > 0 && nums[i] != nums[i - 1])
                {
                    cnt++;
                    maxSequenceCount = max(maxSequenceCount, cnt);
                }
            }
            map[nums[i]]++;
        }

        return maxSequenceCount;
    }

    //Optimised approach  TC->O(n) SC->O(n)
        int longestConsecutiveOptimised(vector<int>& nums) {
        int n = nums.size();
        // If the array is empty
        if (n == 0) return 0; 
    
        // Initialize the longest sequence length
        int longest = 1; 
        unordered_map<int,int> map;
    
        // Put all the array elements into the set
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
    
        /* Traverse the set to 
           find the longest sequence  */
           //Simple for each loop bhi use kr skte hai;
        for (auto it= map.begin();it!=map.end();it++) {
            // Check if 'it' is a starting number of a sequence
            int number=it->first;
            if (map.find(number-1) == map.end()) {
                // Initialize the count of the current sequence
                int cnt = 1; 
                // Starting element of the sequence
                int x = number; 
    
                // Find consecutive numbers in the set
                while (map.find(number + 1) != map.end()) {
                    // Move to the next element in the sequence
                    number = number + 1; 
                    // Increment the count of the sequence
                    cnt = cnt + 1; 
                }
                // Update the longest sequence length
                longest = max(longest, cnt);
            }
        }
        return longest;
    }

    // Without Hashing
    //  TC-O(nlogn)
    //  SC-O(1)
    int longestConsecutiveBetter(vector<int> &nums)
    {
        int maxSequenceCount = 1;
        int cnt = 1;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            else if (i > 0 && nums[i] == nums[i - 1] + 1)
            {
                cnt++;
                maxSequenceCount = max(maxSequenceCount, cnt);
            }
            else
            {
                cnt = 1;
            }
        }

        return maxSequenceCount;
    }
};

int main()
{

    return 0;
}