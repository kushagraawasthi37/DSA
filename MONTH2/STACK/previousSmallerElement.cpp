#include <bits/stdc++.h>
using namespace std;
void previousSmallestEle(vector<int> &vec)
{
    int n = vec.size();
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        // Current element se bade element stack se remove kardo
        while (!s.empty() && vec[i] < s.top())
        {
            s.pop();
        }
        // Stack mai sab Greater element hi the
        if (s.empty())
        {
            ans.push_back(-1);
        }
        // Stack mai Smaller element tha
        else
        {
            ans.push_back(s.top());
        }

        // current element ko stack mai push kardo
        s.push(vec[i]);
    }

    for (int ele : ans)
        cout << ele << " ";

    cout << endl;

    return;
}
int main()
{
    vector<int> vec = {6, 8, 0, 1, 3};
    previousSmallestEle(vec);
    return 0;
}