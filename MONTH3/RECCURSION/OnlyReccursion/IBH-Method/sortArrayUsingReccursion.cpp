#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &vec, int singleEle)
{

    if (vec.size() == 0 || vec[vec.size() - 1] <= singleEle)
    {
        vec.push_back(singleEle);
        return;
    }

    int tempLast = vec.back();
    vec.pop_back();
    insert(vec, singleEle);
    vec.push_back(tempLast);

    return;
}
void sort(vector<int> &vec)
{
    if (vec.size() == 1)
    {
        return;
    }

    int temp = vec[vec.size() - 1];
    vec.pop_back();

    // Hypothesis for smaller input
    sort(vec);

    insert(vec, temp);
    return;
}
int main()
{
    vector<int> vec = {1, 0, 5, 2, 3};
    sort(vec);

    for (int ele : vec)
    {
        cout << ele << " ";
    }

    return 0;
}