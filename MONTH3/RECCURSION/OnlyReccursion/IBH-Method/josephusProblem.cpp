#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k, int startingPos)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }

    startingPos = (startingPos + k) % n;
    int dangerPos = startingPos;
    arr.erase(arr.begin() + dangerPos); // DangerPos par jake us element ko delete kar dega aur baki element ko shift kar dega next time counting dangerous postion se start hogi

    return solve(arr, k, startingPos % arr.size());
}

int main()
{
    int n;
    cout << "Enter n " << endl;
    cin >> n;
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    int k;
    cout << "Enter k " << endl;
    cin >> k;
    k--; // Making it suitable for 0 based indexing array

    cout << "Safest position " << solve(arr, k, 0);
    return 0;
}