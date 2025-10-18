#include <bits/stdc++.h>
using namespace std;

// My approach
void solve(string str, string &output)
{

    string ignoreCaseChange = output;   // store without case change
    string considerCaseChange = output; // store with case change

    // Adding the digit in the string withput worrying about the case
    while (!str.empty() && isdigit(str[0]))
    {
        ignoreCaseChange.push_back(str[0]);
        considerCaseChange.push_back(str[0]);
        str.erase(str.begin() + 0); // Remove the first element from the string
    }

    // Base case
    if (str.length() == 0)
    {
        cout << ignoreCaseChange << endl;
        return;
    }

    // Character si uppercase then convert it to lower case
    if (isupper(str[0]))
    {
        ignoreCaseChange.push_back(str[0]);            // Store without case change
        considerCaseChange.push_back(tolower(str[0])); // Store with case change
    }
    if (islower(str[0]))
    {
        ignoreCaseChange.push_back(str[0]);            // Store without case change
        considerCaseChange.push_back(toupper(str[0])); // Store with case change
    }

    str.erase(str.begin() + 0);
    solve(str, ignoreCaseChange);
    solve(str, considerCaseChange);

    return;
}

void solve1(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }

    if (isalpha(str[0]))
    {
        string op1 = output;
        string op2 = output;

        op1.push_back(toupper(str[0]));
        op2.push_back(tolower(str[0]));

        str.erase(str.begin() + 0);
        solve1(str, op1); // lower case add karo
        solve1(str, op2); // Upper case add akro
    }
    else
    {
        string op1 = output;
        op1.push_back(str[0]);
        str.erase(str.begin() + 0);
        solve1(str, op1);
    }
}
int main()
{
    string str;
    cout << "Enter the string " << endl;
    cin >> str;

    string output = "";
    // solve(str, output);
    solve1(str, output);

    return 0;
}