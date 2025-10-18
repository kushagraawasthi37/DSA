#include <bits/stdc++.h>
using namespace std;

void generateNbitNumber(string str, int ones, int zeros, int n)
{
    if (ones + zeros == n)
    {
        cout << str << endl;
        return;
    }

    if (ones < n)
    {
        string op1 = str;
        op1.push_back('1');
        generateNbitNumber(op1, ones + 1, zeros, n);
    }
    if (zeros < ones)
    {
        string op1 = str;
        op1.push_back('0');
        generateNbitNumber(op1, ones, zeros + 1, n);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    string str = "";
    int ones = 0;
    int zeros = 0;
    generateNbitNumber(str, ones, zeros, n);
    return 0;
}