#include <iostream>
using namespace std;
bool isFreqSame(int frq1[], int frq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (frq1[i] != frq2[i])
        {
            return false;
        }
    }
    return true;
}
bool permutationInString(string s, string str)
{
    if (s.length() > str.length())
    {
        return false;
    }

    // frequency store in array if same type character otherwise we use map instead of array
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 'a';
        freq[idx]++;
    }

    // Search Window

    int winSize = s.length();
    for (int i = 0; i < str.length(); i++)
    {
        int winIdx = 0;
        int idx = i;
        int windowfre[26] = {0};

        while (winIdx < winSize && idx < str.length())
        {
            windowfre[str[idx] - 'a']++;
            winIdx++;
            idx++;
        }

        if (isFreqSame(freq, windowfre))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string str = "eidbaooo";
    string s = "ab";

    cout << permutationInString(s, str);
}