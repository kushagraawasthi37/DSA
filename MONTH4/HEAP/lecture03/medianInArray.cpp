#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
        return 0;

    if (a > b)
        return 1;

    if (a < b)
        return -1;
}

void callMedian(int ele, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &median)
{
    switch (signum(maxheap.size(), minheap.size()))
    {
    case 0:
        if (ele > median)
        {
            minheap.push(ele);
            median = minheap.top();
        }
        else
        {
            maxheap.push(ele);
            median = maxheap.top();
        }
        break;

    case 1:
        if (ele > median)
        {
            minheap.push(ele);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(ele);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        break;

    case -1:
        if (ele > median)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(ele);
            median = (minheap.top() + maxheap.top()) / 2;
        }
        else
        {
            maxheap.push(ele);
            median = (minheap.top() + maxheap.top()) / 2;
        }
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = -1;

    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }

    return ans;
}

int main()
{
    return 0;
}