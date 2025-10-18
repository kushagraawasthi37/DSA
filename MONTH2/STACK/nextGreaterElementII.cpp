#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterEleII(vector<int> &vec)
{
    int n = vec.size();
    vector<int> ans(n, 0);
    stack<int> s;
    
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        // i% n for valid index
        while (s.size() > 0 && vec[s.top()] <= vec[i % n])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i % n] = -1;
        }
        else
        {
            ans[i % n] = vec[s.top()];
        }
        s.push(i % n);
    }
    return ans;
}
int main()
{
    vector<int> vec = {1, 2, 3, 34, 4};
    vector<int> ans = nextGreaterEleII(vec);
    return 0;
}