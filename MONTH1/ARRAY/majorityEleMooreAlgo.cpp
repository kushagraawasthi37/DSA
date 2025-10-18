#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int optimalMaj(vector<int> &vec)
{
    // Time: O(n log n) (due to sorting)
    // Space:  O(1)

    sort(vec.begin(), vec.end());
    int n = vec.size();
    int ans = vec[0];
    int fre = 1;

    for (int i = 1; i < n; i++)
    {
        if (vec[i] == vec[i - 1])
        {
            fre++;

            // Final result
            if (fre > n / 2)
                return ans;
        }

        else
        {
            fre = 1;
            ans = vec[i];
        }
    }

    return -1;
}
int optimalMajPer(vector<int> &vec)
{
    // Time: O(n log n) (due to sorting)
    // Space:  O(1)

    sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}

int mooreAlgo(vector<int> &vec, int n)
{
    int fre = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (fre == 0)
            ans = vec[i];

        if (ans == vec[i])
            fre++;

        else
            fre--;
    }

    // If it is not given that majority ELement exist or not
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] == ans)
            count++;
    }

    if (count > n / 2)
        return ans;

    else
        cout << "No Majority element exist " << endl;

    return -1;
}
int main()
{
    // Brute force->sabki frequency nikal lu phir check kru O(n^2)
    // Optimise -> pahele sort krdo then frequency nikalo in linear time

    vector<int> vec = {1, 3, 2, 2, 3, 23, 33, 63};
    int n = vec.size();

    cout << "Majority elment  using optimal approach " << optimalMaj(vec) << endl;
    cout << "Majority Element by Moore Algorithm " << mooreAlgo(vec, n) << endl;

    return 0;
}