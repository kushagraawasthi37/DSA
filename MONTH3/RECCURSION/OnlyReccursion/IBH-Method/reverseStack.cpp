#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int lastEle)
{
    if (s.empty())
    {
        s.push(lastEle);
        return;
    }

    int temp = s.top();
    s.pop();
    // Hypothesis for smaller input
    solve(s, lastEle);
    s.push(temp); // induction step

    return;
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }

    int lastEle = s.top();
    s.pop();
    // Hypothesis for smaller input
    reverseStack(s); // hypothesis step

    solve(s, lastEle); // Induction step
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(0);
    s.push(5);
    s.push(2);
    s.push(3);

    // Solve using the reccuarison
    /*

    hypothesis  ==> reverseStack(s)=> s stack ko reverse kar dega
    Base case  ==> stack with 1 element is already reversed
    Induction  ==>reversed stack mai last element ko last mai place kar denge
    */

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}