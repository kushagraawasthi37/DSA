#include <bits/stdc++.h>
using namespace std;

int largestRectangleInHistogram(vector<int> &vec)
{
    vector<int> left;
    vector<int> right;

    int n = vec.size();
    stack<int> st;

    // Calculation of Left Boundary->Left First Smaller
    for (int i = 0; i < n; i++)
    {

        // Check for 1st smaller element
        while (!st.empty() && vec[i] < vec[st.top()])
        {
            st.pop();
        }

        if (st.empty())
        {
            left.push_back(-1);
        }
        else
        {
            left.push_back(st.top());
        }
        st.push(i);
    }

    // Empty Stack
    while (!st.empty())
    {
        st.pop();
    }

    // Calculation of Right Boundary->Right first smaller
    for (int i = n - 1; i >= 0; i--)
    {

        // Check for 1st smaller element
        while (!st.empty() && vec[i] < vec[st.top()])
        {
            st.pop();
        }

        if (st.empty())
        {
            // No Smaller element in right then end is boundary
            right.push_back(n);
        }
        else
        {
            right.push_back(st.top());
        }
        st.push(i);
    }

    reverse(right.begin(), right.end());

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int height = vec[i];
        int width = right[i] - left[i] - 1;

        int currArea = height * width;
        ans = max(currArea, ans);
    }

    return ans;
}

int main()
{
    vector<int> vec = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleInHistogram(vec);
    return 0;
}