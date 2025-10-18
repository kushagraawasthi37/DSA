#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isValidPartition(vector<int> &arr, int n, int AllowedDis, int cow, vector<int> &position)
{
    position.clear();

    int lastPos = arr[0]; // First cow at 0 Index

    position.push_back(lastPos); // First cow placed at arr[0]

    int curCow = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - lastPos) >= AllowedDis)
        {
            curCow++;
            lastPos = arr[i];
            position.push_back(lastPos); // Update Position
            if (curCow == cow)
            {
                return true;
            }
        }
    }

    return false;
}

int maxMinDistanceBetweenCows(vector<int> &arr, int n, int cow, vector<int> &finalPosition)
{
    sort(arr.begin(), arr.end());

    int e = arr[n - 1] - arr[0];
    int s = 1;
    int ans;

    // Additonal step
    vector<int> tempposition;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isValidPartition(arr, n, mid, cow, tempposition))
        {
            // Minimum Distance must be maximum
            ans = mid;
            s = mid + 1;
            finalPosition = tempposition; // Save best Final answer
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> stallArray = {1, 2, 8, 4, 9};
    int n = stallArray.size();
    vector<int> position;
    int cow;

    cout << "Stalls available at positions: ";
    for (int pos : stallArray)
        cout << pos << " ";
    cout << "\n\nEnter the number of cows: ";
    cin >> cow;

    int maxMinDist = maxMinDistanceBetweenCows(stallArray, n, cow, position);

    cout << "\nMaximum minimum distance between cows: " << maxMinDist << endl;
    cout << "Cows placed at stalls: ";
    for (int p : position)
        cout << p << " ";
    cout << endl;

    return 0;
}