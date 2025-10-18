#include <bits/stdc++.h>
using namespace std;

// FIRST NON REPEATING CHARACTER IN STREAM
// FIND UNIQUE CHARACTER IN STRING

char UniqueCharacterInString(string str)
{
    unordered_map<char, int> m;
    queue<int> q;

    for (int i = 0; i < str.length(); i++)
    {
        if (m.find(str[i]) == m.end())
        {
            q.push(str[i]);
        }
        m[str[i]]++;

        while (!q.empty() && m[str[i]] > 1)
        {
            q.pop();
        }
    }

    if (q.empty())
    {
        return '1';
    }

    return q.front();
}

int main()
{
    string str = "aabbcde";
    cout << "UNIQUE ELEMENT IN THIS STRING " << UniqueCharacterInString(str);
    return 0;
}