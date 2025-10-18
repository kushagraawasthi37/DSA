#include <bits/stdc++.h>
using namespace std;

class myStack
{

    queue<int> q1;
    queue<int> q2;

public:
    myStack()
    {
    }

    void push(int val)
    { // O(n)

        // COPY Q1 TO Q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // PUSH NEW ELEMENT IN Q1
        q1.push(val);

        // RETUR COPY BACK Q2 IN Q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop()
    { // O(1)
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    { // O(1)
        return q1.front();
    }

    bool empty()
    { // O(1)
        return q1.empty();
    }
};

int main()
{
    myStack *s = new myStack();

    s->push(10);
    s->push(20);
    s->push(30);

    cout << "Top: " << s->top() << endl;    // Should print 30
    cout << "Popped: " << s->pop() << endl; // Should print 30

    cout << "Top: " << s->top() << endl; // Should print 20
    s->push(40);
    cout << "Top after pushing 40: " << s->top() << endl; // Should print 40

    while (!s->empty())
    {
        cout << "Popped: " << s->pop() << endl;
    }

    cout << "Is empty? " << (s->empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}
