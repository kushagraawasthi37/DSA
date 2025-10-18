#include <bits/stdc++.h>
using namespace std;

class minStack
{
    stack<pair<int, int>> s;

    void push1(int val)
    {
        // val(first), minval(second)
        // AGAR STACK EMPTY HAI TO MINIMUM VALUE BHI FIRST VALUE HI HOGI
        if (s.empty())
        {
            s.push({val, val});
        }

        else
        {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop1()
    {
        s.pop();
    }

    int top1()
    {
        return s.top().first;
    }
    int minValue1()
    {
        return s.top().second;
    }

    // Min STACK APPROACH II

    stack<long long int> st;
    long long int minValue;

    int getMin()
    {
        return minValue;
    }
    void push2(int val)
    {
        if (s.empty())
        {
            st.push(val);
            minValue = val;
        }
        // AGAR AISE VALUE HAI JO MINIMUM VALUE KO AFFECT KRTI HAI TO  HUM YE FORMULA USE KRKE REAL VALUE FIND KARENGE
        if (val < minValue)
        {
            st.push(2 * val - minValue);
            minValue = val;
        }
        else
        {
            // VALUE MINIMUM VALUE SE BADI HAI
            st.push(val);
        }
    }
    void pop()
    {
        // AGAR AISE VALUE HAI JO MINIMUM VALUE KO AFFECT KRTI HAI TO  HUM YE FORMULA USE KRKE REAL VALUE FIND KARENGE
        if (st.top() < minValue)
        {
            minValue = 2 * minValue - st.top();
        }
        s.pop();
    }

    int top()
    {
        if (st.top() < minValue)
        {
            return minValue;
        }
        else
        {
            return st.top();
        }
    }
};
int main()

{
    return 0;
}