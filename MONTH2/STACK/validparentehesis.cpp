
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> s;
        int r = 0;
        int n = str.length();

        while (r < n)
        {
            if (str[r] == '(' || str[r] == '{' || str[r] == '[')
            {
                s.push(str[r]);
                r++;
            }
            else
            {
                if (!s.empty())
                {
                    if (str[r] == ')' && s.top() == '(' ||
                        str[r] == ']' && s.top() == '[' ||
                        str[r] == '}' && s.top() == '{')
                    {
                        s.pop();
                        r++;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        return s.empty();
    }
};

int main()
{
    string str = "()[{}()]";

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to check if the
    string is valid */
    bool ans = sol.isValid(str);

    if (ans)
        cout << "The given string is valid.";
    else
        cout << "The given string is invalid.";

    return 0;
}