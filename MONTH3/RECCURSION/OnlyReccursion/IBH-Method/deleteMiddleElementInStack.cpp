#include <bits/stdc++.h>
using namespace std;

void deleteMiddleElement(stack<int> &s, int n)
{

    if (s.empty())
    {
        return;
    }
    if (n == 0)
    {
        s.pop();
        return;
    }

    int topEle = s.top();
    s.pop();
    deleteMiddleElement(s, n - 1);
    s.push(topEle);

    return;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(0);
    s.push(5);
    s.push(2);
    s.push(3);

    int n = s.size();
    deleteMiddleElement(s, n / 2);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}