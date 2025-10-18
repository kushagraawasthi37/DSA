#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int powerOFNumber(int x, int n, int m)
    {
        long long ans = 1, base = x;

        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = ans * base;
                if (ans > m)
                    return 2; // mid^n > m
            }

            n = n / 2; // Halve exponent AFTER multiplication
            if (n > 0)
            {
                base = base * base;
                if (base > m)
                    return 2; // mid^n > m
            }
        }

        if (ans == m)
            return 1;
        return 0;
    }

    int NthRoot(int N, int M)
    {
        int low = 1, high = M;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int midN = powerOFNumber(mid, N, M);

            if (midN == 1)
                return mid;
            else if (midN == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}