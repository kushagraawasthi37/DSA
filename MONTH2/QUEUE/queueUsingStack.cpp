#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
    }

    void push(int val)
    {
        // COPY S1 TO S2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // PUSH NEW ELEMENT IN S1
        s1.push(val);

        // RETURN COPY BACK S2 IN S1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop()
    {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl; // Should print 10

    cout << "Popped: " << q.pop() << endl; // Should print 10
    cout << "Popped: " << q.pop() << endl; // Should print 20

    cout << "Front: " << q.peek() << endl; // Should print 30

    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << endl; // Should print No

    cout << "Popped: " << q.pop() << endl; // Should print 30

    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}
