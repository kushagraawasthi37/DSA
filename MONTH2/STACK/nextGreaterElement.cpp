#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void nextGreaterElement(vector<int> &vec)
{
    vector<int> ans;
    stack<int> st;


    // TRY TO APPROACH FROM REVERSE ORDER->Now it become prev smaller element question

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        // JO ELEMENT KABHI NEXTGREATER ELEMENT BAN NAHI SKTE
        while (st.size() > 0 && st.top() <= vec[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(vec[i]);
    }

    for (int ele : ans)
    {
        cout << ele << " ";
    }
}

vector<int> nextGreaterElementI(vector<int> &vec1, vector<int> &vec2)
{
    vector<int> ans;
    stack<int> st;
    unordered_map<int, int> m;

    for (int i = vec2.size() - 1; i >= 0; i--)
    {
        // JO ELEMENT KABHI NEXT GREATER ELEMENT BAN NAHI SKTE
        while (st.size() > 0 && st.top() <= vec2[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            m[vec2[i]] = -1;
        }
        else
        {
            m[vec2[i]] = st.top();
        }
        st.push(vec2[i]);
    }
    for (int i = 0; i < vec1.size(); i++)
    {
        ans.push_back(m[vec1[i]]);
    }

    return ans;
}
int main()
{
    vector<int> vec = {6, 8, 0, 1, 3};
    nextGreaterElement(vec);

    return 0;
}