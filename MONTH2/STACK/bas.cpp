#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Stack
{
    // Implementation using vector (array could also be used, but stack will be of static size)
    // vector<int> v;
    list<int> li;

public:
    void push(int n)
    {
        // v.push_back(n);
        li.push_front(n);
    }
    void pop()
    {
        // v.pop_back();
        li.pop_front();
    }
    int top()
    {
        // return v[v.size() - 1];
        return li.front();
    }
    bool empty()
    {
        // return v.size() == 0; // Simplified condition
        return li.size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout << "Top of Stack: " << s.top() << endl;
        s.pop(); // Pop the top element to avoid an infinite loop
    }

    // Implementation of stack using C++ STL
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    while (!s1.empty())
    {
        cout << s1.top() << " " << endl;
        s1.pop();
    }
    return 0;
}
