#include <bits/stdc++.h>
using namespace std;

void solve(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }

    string op1 = output; // With uppercase
    string op2 = output; // Same

    op1.push_back(toupper(str[0]));
    op2.push_back(str[0]);

    string str2= str.substr(1, str.length() - 1);
    solve(str2, op1);
    solve(str2, op2);
}

int main()
{
    // int ch = 'A'-'a';//32

    string str;
    cout << "Enter the string " << endl;
    cin >> str;

    string output = "";

    solve(str, output);

    return 0;
}