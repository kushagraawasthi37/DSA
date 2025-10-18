#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output, int idx)
{
    if (idx == input.length())
    {
        cout << output << endl;
        return;
    }
    string takingSpace = output + "_"; // taking the space
    string IgnoreSpace = output;       // Not taking the space

    takingSpace.push_back(input[idx]);
    IgnoreSpace.push_back(input[idx]);

    solve(input, takingSpace, idx + 1);
    solve(input, IgnoreSpace, idx + 1);
}

int main()
{
    string str;
    cout << "Enter the string " << endl;
    cin >> str;

    int idx = 1;
    string op = "";
    op.push_back(str[0]);

    solve(str, op, idx);

    return 0;
}