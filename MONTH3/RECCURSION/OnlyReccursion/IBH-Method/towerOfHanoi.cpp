#include <bits/stdc++.h>
using namespace std;

void solve(int src, int des, int helper, int n, int &count)
{
    count++;
    if (n == 1)
    {
        cout << "moving " << n << " plate from " << src << " to " << des << endl;
        return;
    }

    solve(src, helper, des, n - 1, count);

    cout << "moving " << n << " plate from " << src << " to " << des << endl;
    solve(helper, des, src, n - 1, count);
}
int main()
{
    int src = 1;
    int helper = 2;
    int destination = 3;
    int count = 0;

    int n;
    cout << "enter the number of plate :" << endl;
    cin >> n;

    solve(src, destination, helper, n, count);

    cout << "Number of step " << count << endl;

    return 0;
}