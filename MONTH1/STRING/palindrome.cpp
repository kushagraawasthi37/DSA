#include <iostream>
using namespace std;
bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s < e)
    {
        if (!isAlphaNum(str[s]))
        {
            s++;
            continue;
        }
        if (!isAlphaNum(str[e]))
        {
            e--;
            continue;
        }
        if (tolower(str[s]) != tolower(str[e]))
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main()
{
    string str = "madaM";
    cout << isPalindrome(str);
    return 0;
}