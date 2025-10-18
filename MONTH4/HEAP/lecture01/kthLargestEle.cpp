#include <bits/stdc++.h>
using namespace std;

int kthLargestEle(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minheap;

    // Step 1: start ke k element ka min heap bna diya
    for (int i = 0; i < k; i++)
    {
        minheap.push(arr[i]);
    }

    // Step 2: agar aage koi element array mai top element se bada hai to wo aajyega to top remove krdege isse last mai heap mai smallest k element bachege

    for (int i = k; i < n; i++)
    {
        if (minheap.top() < arr[i])
        {
            minheap.pop();
            minheap.push(arr[i]);
        }
    }

    return minheap.top();
}
int main()
{
    vector<int> vec = {7, 10, 4, 20, 16, 6};
    cout << kthLargestEle(vec, 2);
    return 0;
}