#include <bits/stdc++.h>
using namespace std;

void printSubset(string s, string &op)
{
    if (s.length() == 0)
    {
        cout << op << " " << endl;
        return;
    }

    string takingCurrentEle = op; // Current element nahi lenge
    string ignoreCurrEle = op;
    ignoreCurrEle.push_back(s[0]);                       // Current element lenge
    string newS = s.substr(1, s.length() - 1); // Starting element remove kar denge
    printSubset(newS, ignoreCurrEle);
    printSubset(newS, takingCurrentEle);
}

int main()
{
    string s;
    cin >> s;

    string op = "";
    printSubset(s, op);
    return 0;
}