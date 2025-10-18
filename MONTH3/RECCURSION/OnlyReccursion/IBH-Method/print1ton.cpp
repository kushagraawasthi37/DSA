#include <bits/stdc++.h>

using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";

    // Hypothesis for smaller input
    print(n - 1);
    // cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter the n ";
    cin >> n;
    print(n);
    return 0;
}