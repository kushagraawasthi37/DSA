#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int lastEle)
{

    // base conditon
    if (s.empty() || s.top() <= lastEle)
    {
        s.push(lastEle);
        return;
    }

    int topEle = s.top();
    s.pop();

    insert(s, lastEle);
    s.push(topEle);
    return;
}

void sort(stack<int> &s)
{
    // base conditon
    if (s.size() == 1)
    {
        return;
    }

    // Hypothesis for smaller input
    // Store the last ele
    int topEle = s.top();
    s.pop(); // decreasing the size of stack
    sort(s);

    // induction
    insert(s, topEle);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(0);
    s.push(5);
    s.push(2);
    s.push(3);

    sort(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}