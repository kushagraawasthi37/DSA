#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
void stockSpan(vector<int> &vec, vector<int> &ans)
{
    // Span maximum consecutive previous +current day in which price os stock is less than current day
    int n = vec.size();
    stack<int> st;

     st.push(0);
    ans[0] = 1;  // First element always has span 1

    for (int i = 1; i < n; i++)
    {
        // Current element previous element se bada hai
        while (!st.empty() && vec[i] >= vec[st.top()])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - st.top();
        }
        st.push(i);
    }
}

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(price.size(), 0);
    stockSpan(price, ans);
    for (int ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}
