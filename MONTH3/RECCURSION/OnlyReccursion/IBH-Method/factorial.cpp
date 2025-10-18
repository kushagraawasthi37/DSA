#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    // Hypothesis for smaller input
    return factorial(n - 1) * n;
}

int main()
{
    int n;
    cout << "enter n :";

    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}