#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseWordInString(string str)
{
    string ans = "";

    // Reverse String
    reverse(str.begin(), str.end());

    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        // words are seperated
        string word = "";
        while (i < n && str[i] != ' ')
        {
            word += str[i];
            i++;
        }

        reverse(word.begin(), word.end());
        // reverse the word
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }

    ans.substr(1);

    return ans;
}
int main()
{
    string str = "world new to welcome";
    cout << reverseWordInString(str);
    return 0;
}