#include <bits/stdc++.h>
using namespace std;

int maxFre(vector<int> &vec)
{
    int maxFre = -1;
    unordered_map<int, int> m;

    for (int i = 0; i < vec.size(); i++)
    {
        m[vec[i]]++;
        maxFre = max(maxFre, m[vec[i]]);
    }

    for (auto i : m)
    {
        if (i.second == maxFre)
        {
            return i.first;
        }
    }
}

int main()
{
    vector<int> vec = {2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2, -6};
    cout << maxFre(vec);
    return 0;
}