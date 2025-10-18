
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool validParenthesis(string str)
{
    // Valid condition => last opening bracket = first closing bracket
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        // Opening character
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }

        // Closing character
        else
        {
            // More closing brackets than opening brackets
            if (st.empty())
            {
                return false;
            }

            // Check if the closing bracket matches the top of the stack
            if ((st.top() == '(' && str[i] == ')') ||
                (st.top() == '{' && str[i] == '}') ||
                (st.top() == '[' && str[i] == ']'))
            {
                st.pop();
            }
            else
            {
                return false; // If no match, return false
            }
        }
    }

    // If stack is empty at the end, it means parentheses are balanced
    return st.empty();
}

int main()
{
    string str = "{(())}";
    cout << validParenthesis(str); // Output should be 1 (true) for valid parentheses
    return 0;
}
