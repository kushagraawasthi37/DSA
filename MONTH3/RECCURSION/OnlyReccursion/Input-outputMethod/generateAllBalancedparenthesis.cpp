#include <bits/stdc++.h>
using namespace std;

void generateBalancedParenthesis(string &str, int open, int closing, int n)
{
    if (open == closing && (open + closing) == 2 * n)
    {
        cout << str << endl;
        return;
    }
    if (open < n)
    {
        str.push_back('(');
        generateBalancedParenthesis(str, open + 1, closing, n);
        str.pop_back();
    }
    if (closing < open)
    {
        str.push_back(')');
        generateBalancedParenthesis(str, open, closing + 1, n);
        str.pop_back();
    }

    return;
}

void solveBalanceparenthesis(string &s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        cout << s << endl;
        return;
    }

    if (open != 0)
    {
        string op1 = s;
        op1.push_back('(');
        solveBalanceparenthesis(op1, open - 1, close);
    }
    if (close > open)
    {
        string op2 = s;
        op2.push_back(')');
        solveBalanceparenthesis(op2, open, close - 1);
    }
}

int main()
{
    int n;
    cout << "Enter n " << endl;
    cin >> n;

    string output = "";
    int open = 0;
    int closing = 0;
    // generateBalancedParenthesis(output, open, closing, n);
    solveBalanceparenthesis(output, n, n);
    return 0;
}