#include <iostream>
#include <vector>
using namespace std;

// Power x^n using binary exponentiation
// Binary form of any number can have maximum ( logn base 2)+1 digit

double binaryExp(double x, int n)
{
    long long biform = n;
    double ans = 1.0;

    if (x == 0 || x == 1)
        return x;

    if (biform < 0)
    {
        x = 1 / x;
        biform = -biform;
    }

    while (biform > 0)
    {
        if (biform % 2 == 1)
        {
            ans *= x;
        }
        biform /= 2;

        if (biform > 0)
        {
            x *= x;
        }
    }
    return ans;
}
int main()
{
    cout << binaryExp(2, 102);
    return 0;
}