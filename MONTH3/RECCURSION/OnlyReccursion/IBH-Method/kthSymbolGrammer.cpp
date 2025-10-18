#include <bits/stdc++.h>
using namespace std;

int KthSymbolInGrammer(int n, int k)
{
    // base case
    if (n == 1 || k == 1)
    {
        return 0;
    }

    int mid = pow(2, n - 1) / 2;

    // Starting ke element same hai as previous row
    if (k <= mid)
    {
        int ans = KthSymbolInGrammer(n - 1, k);

        // Hypothesis for smaller input
        return ans;
    }

    // Mid ke baad ke element jo hai wo complement hai previous row ke element ke
    else
    {
        // Hypothesis for smaller element and ! is a induction step
        int ans = !KthSymbolInGrammer(n - 1, k - mid);
        return ans;
    }

    return 0;
}

int main()
{
    int n;
    int k;
    KthSymbolInGrammer(n, k);

    return 0;
}