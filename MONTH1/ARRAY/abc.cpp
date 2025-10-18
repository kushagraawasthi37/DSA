#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int reverseInterger(int n)
{
    int ans = 0;
    int rem = 0;
    while (n > 0)
    {
        // 1 3 8 5 8
        rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }

    return ans;
}


int main()
{
    int n = 13858;
    cout << reverseInterger(n);
    return 0;
}