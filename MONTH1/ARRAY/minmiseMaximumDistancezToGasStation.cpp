#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Function to minimize the maximum
    distance between gas stations Brute Force */
    double minimiseMaxDistanceBrute(vector<int> &arr, int k)
    {
        int n = arr.size();

        /* Array to store how many gas
        stations are placed in each section*/
        vector<int> howMany(n - 1, 0);

        // Place k gas stations
        for (int gasStations = 1; gasStations <= k; gasStations++)
        {
            double maxSection = -1;
            int maxInd = -1;

            /* Find the maximum section
            and insert the gas station*/
            for (int i = 0; i < n - 1; i++)
            {
                double diff = arr[i + 1] - arr[i];
                double sectionLength = diff / (howMany[i] + 1);

                /* Update the maximum section
                length and its index */
                if (sectionLength > maxSection)
                {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            /* Insert the current gas
            station into the section */
            howMany[maxInd]++;
        }

        // Find the maximum distance (answer)
        double maxAns = -1;
        for (int i = 0; i < n - 1; i++)
        {
            double diff = arr[i + 1] - arr[i];
            double sectionLength = diff / (howMany[i] + 1);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }

    // Better Approach we are getting the O(K*n)// due to nested loop we used for the the calculation of the maximum section and its index if we use some data structure that gives us the maximum element in less time than O(n) we use it(Priority queue(maxheap));

    double minimiseMaxDistanceBrute(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<pair<long double, int>> maxheap;

        // Pushing all the section in maxheap
        for (int i = 0; i < n - 1; i++)
        {
            maxheap.push({(long double)(arr[i + 1] - arr[i]), i});
        }

        /* Array to store how many gas stations are placed in each section*/
        vector<int> howMany(n - 1, 0);

        // Place k gas stations
        for (int gasStations = 1; gasStations <= k; gasStations++)
        {
            /* Find the maximum section and insert the gas station*/
            auto top = maxheap.top();
            maxheap.pop();

            double maxidx = top.second;
            // Ek station yaha par insert kardo
            howMany[maxidx]++;

            // Maxheap ko update kardo with new difference
            long double inidiff = (long double)(arr[maxidx + 1] - arr[maxidx]);
            long double newSecLen = inidiff / (long double)(howMany[maxidx] + 1);

            // Logn complexity
            maxheap.push({newSecLen, maxidx});
        }

        return maxheap.top().first;
    }



    int numberOfGasStationsRequired(long double dist, vector<int> &arr)
    {
        // Size of the array
        int n = arr.size();
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {

            /* Calculate number of gas stations  needed between two points*/
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);

            // Adjust if exact distance fits perfectly
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
            {
                numberInBetween--;
            }

            cnt += numberInBetween;
        }
        return cnt;
    }

    /* Function to minimize the maximum
    distance between gas stations*/
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        long double low = 0;
        long double high = 0;

        /* Find the maximum distance between
        consecutive gas stations*/
        for (int i = 0; i < n - 1; i++)
        {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        /* Apply Binary search to find the
        minimum possible maximum distance*/
        long double diff = 1e-6;
        while (high - low > diff)
        {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);

            /* Adjust the search range based on
            the number of gas stations required*/
            if (cnt > k)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        // Return the smallest maximum distance found
        return high;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    // Create an instance of the Solution class
    Solution sol;

    // Call the minimiseMaxDistance method and print the result
    long double ans = sol.minimiseMaxDistanceBrute(arr, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}
