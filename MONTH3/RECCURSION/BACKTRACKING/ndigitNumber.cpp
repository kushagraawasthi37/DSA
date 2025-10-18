#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &vec, vector<int> &res)
{

    if (n == 0)
    {
        int ans = 0;
        // Converting the vector to number
        for (int ele : vec)
        {
            ans = ans * 10 + ele;
        }
        res.push_back(ans);
    }

    for (int i = 1; i <= 9; i++)
    {
        // Current digit is greater thann next digit skip it
        if (!vec.empty() && vec.back() >= i)
        {
            continue;
        }
        else
        {
            vec.push_back(i);
            solve(n - 1, vec, res);
            vec.pop_back();
        }
    }
}

int main()
{
    int n;
    cout << "Enter n " << endl;
    cin >> n;

    vector<int> res;
    vector<int> temp;

    if (n == 1)
    {
        for (int i = 0; i <= 0; i++)
        {
            res.push_back(i);
        }
    }

    solve(n, temp, res);

    for (int ele : res)
    {
        cout << ele << " ";
    }

    return 0;
}