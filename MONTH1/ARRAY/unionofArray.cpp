#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> output;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            if (output.empty() || output.back() != a[i])
                output.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            if (output.empty() || output.back() != a[i])
                output.push_back(a[i]);
            i++;
        }
        else
        {
            if (output.empty() || output.back() != b[j])
                output.push_back(b[j]);
            j++;
        }
    }

    // Add remaining elements of a
    while (i < a.size())
    {
        if (output.empty() || output.back() != a[i])
            output.push_back(a[i]);
        i++;
    }

    // Add remaining elements of b
    while (j < b.size())
    {
        if (output.empty() || output.back() != b[j])
            output.push_back(b[j]);
        j++;
    }

    return output;
}
int main()
{
    return 0;
}