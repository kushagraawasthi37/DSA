#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &vec, int i, int n)
{
    // 0-Based Indexing
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[largest] < vec[left])
    {
        largest = left;
    }
    if (right < n && vec[largest] < vec[right])
    {
        largest = right;
    }

    // Largest change hua
    if (largest != i)
    {
        swap(vec[largest], vec[i]);
        heapify(vec, largest, n);
    }
}

vector<int> merge2SortedHeap(vector<int> &a, vector<int> &b)
{
    vector<int> ans;

    for (int ele : a)
    {
        ans.push_back(ele);
    }
    for (int ele : b)
    {
        ans.push_back(ele);
    }

    int sz = ans.size();
    for (int i = sz / 2 - 1; i >= 0; i--)
    {
        heapify(ans, i, sz);
    }

    return ans;
}

void printHeap(vector<int> &heap)
{
    for (int ele : heap)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> ans = merge2SortedHeap(a, b);

    printHeap(ans);

    return 0;
}