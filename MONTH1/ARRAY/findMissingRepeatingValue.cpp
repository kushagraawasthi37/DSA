#include <bits/stdc++.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int duplicateInteger(vector<int> &arr)
{

    // TC-> O(n);
    // SC-> O(n);
    int n = arr.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        // Check if already entry present in map or not
        if (m.find(arr[i]) != m.end())
        {
            return arr[i];
        }

        // Inserting into Map
        m[arr[i]]++;
    }
}

/**************************** Floyd's Cycle Detection algorithm ( Tortoise and Hare algorithm)  ****************************/

int optduplicateInteger(vector<int> &arr)
{
    // TC-> O(n);
    // SC-> O(1);

    // Slow faster Pointer approach-> assume array as a linked list where index =node and element is next node;0;

    int n = arr.size();
    int slowptr = 0;
    int fastptr = 0;

    // Step 1:
    // Phase 1: Find intersection point
    do
    {

        // Check bounds BEFORE dereferencing
        if (slowptr < 0 || slowptr >= n ||
            fastptr < 0 || fastptr >= n ||
            arr[fastptr] < 0 || arr[fastptr] >= n ||
            arr[arr[fastptr]] < 0 || arr[arr[fastptr]] >= n)
            return -1; // No cycle / invalid input

        slowptr = arr[slowptr];      //+1 kar rhe ho
        fastptr = arr[arr[fastptr]]; //+2 kar rhe ho
    } while (slowptr != fastptr);

    // Step 2:slow ko start se chalao and  dono ko 1 step se aage badhao
    slowptr = 0;
    while (slowptr != fastptr)
    {
        slowptr = arr[slowptr];
        fastptr = arr[fastptr];
    }
    // After second step ye mathematical proved hai ki ye dono same point ko point krenge jo repeating hoga
    return slowptr;
}

pair<int, int> findMissingAndRepeatingValue(vector<vector<int>> &v /*1 to n*n element*/)
{
    pair<int, int> p;
    unordered_set<int> s;
    int n = v.size();
    int repeatingValue, missingValue;

    // finding Repeating value
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (s.find(v[i][j]) != s.end())
            {
                repeatingValue = v[i][j];
                p.first = repeatingValue;

                break;
            }
            s.insert(v[i][j]);
        }
    }
    // Find Missing value

    int actualSum = 0;
    int idealSum;
    idealSum = (n * n) * (n * n + 1) / 2;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            actualSum += v[i][j];
        }
    }

    missingValue = idealSum + repeatingValue - actualSum;

    p.second = missingValue;

    return p;
}


    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbersOptimisedII(vector<int>& nums) {
        
        // Size of the array
        long long n = nums.size(); 

        // Sum of first n natural numbers
        long long SN = (n * (n + 1)) / 2;
        
        // Sum of squares of first n natural numbers
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        /*Calculate actual sum (S) and sum 
        of squares (S2) of array elements*/
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        //Compute the difference values
        long long val1 = S - SN; 
        
        // S2 - S2n = X^2 - Y^2
        long long val2 = S2 - S2N; 

        //Calculate X + Y using X + Y = (X^2 - Y^2) / (X - Y)
        val2 = val2 / val1;

        /* Calculate X and Y from X + Y and X - Y
         X = ((X + Y) + (X - Y)) / 2
         Y = X - (X - Y)*/
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        // Return the results as {repeating, missing}
        return {(int)x, (int)y};
    }



int main()
{

    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {6, 7, 8}};
    // pair<int, int> p = findMissingAndRepeatingValue(vec);
    // cout << "Missing Element " << p.second << " Repeating element " << p.first << endl;

    vector<int> vec1 = {1, 2, 3, 2, 4, 6};
    cout << "Using set/Map " << duplicateInteger(vec1) << endl;
    cout << "Optimised Approached " << optduplicateInteger(vec1) << endl;

    return 0;
}