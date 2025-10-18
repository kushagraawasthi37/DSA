#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string stringCompression(string chars)
{
    int n = chars.length();
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;

        while ((i < n) && chars[i] == ch)
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            chars[idx] = ch;
            idx++;
        }
        else
        {
            chars[idx] = ch;
            idx++;
            string str = to_string(count);
            for (char dig : str)
            {
                chars[idx] = dig;
                idx++;
            }
        }
        i--;
    }
    chars.resize(idx);
    return chars;
}
int main()
{
    string str = "aabbccc";
    cout << stringCompression(str) << endl;
    return 0;
}