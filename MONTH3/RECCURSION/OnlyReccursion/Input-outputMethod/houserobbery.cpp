#include <bits/stdc++.h>
using namespace std;
int maxAmountRob(vector<int> &house, int n, vector<int> &ans, int curHouse)
{
    // NO HOUSE REMAINING CASE OR 0 HOUSE CASE
    if (n == 0 || curHouse >= n)
        return 0;

    // CHECK IF RESULLT IS ALREADY COMPUTED->DP USED(RECC+MEMORISATION)

    if (ans[curHouse] != -1)
        return ans[curHouse];

    // EVERY HOUESE HAS TWO CHOICE EITHER LOOTED OR NOT LOOTED +2 BECAUSE ADJACENT HOUSE IS NOT ALLOWED

    // IF CUURENT HOUSE IS BEING PICK FOR ROBBERY
    int pick = house[curHouse] + maxAmountRob(house, n, ans, curHouse + 2);

    // BEING NOTPICK FOR ROBBERY
    int notPick = maxAmountRob(house, n, ans, curHouse + 1);

    ans[curHouse] = max(pick, notPick);

    return ans[curHouse];
}

int main()
{
    vector<int> house = {6, 7, 1, 3, 8, 2, 4};
    vector<int> ans(7, -1);
    cout << maxAmountRob(house, 7, ans, 0);
    return 0;
}