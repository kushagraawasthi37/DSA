#include <bits/stdc++.h>
using namespace std;
void combinationSum(int arr[], int target, int idx, vector<vector<int>> &ans, vector<int> &temp, int n)
{

    // BASE CASE SUCCESSFUL COMBINATION
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    // BASE CASE FAILURE COMBINATION
    if (idx == n || target < 0)
        return;

    temp.push_back(arr[idx]);

    
    // MULTIPLE INCLUDE
    combinationSum(arr, (target - arr[idx]), idx, ans, temp, n);

    // BACKTRACKING STEP
    temp.pop_back();

    // EXCLUDED CASE
    combinationSum(arr, target, idx + 1, ans, temp, n);
    return;
}

int main()
{
    int arr[] = {2, 3, 5};
    vector<int> temp;
    vector<vector<int>> ans;
    int target = 8;
    combinationSum(arr, target, 0, ans, temp, 3);

    cout << "{";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j];
            if (j + 1 < ans[i].size())
                cout << ", ";
        }
        cout << "}";
        if (i + 1 < ans.size())
            cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
