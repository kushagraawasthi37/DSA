#include <bits/stdc++.h>
using namespace std;

int minimumCostOfRopes(int arr[], long long n)
{
    // Create a minheap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // Insert all element in minheap
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;

    // 2 minimum element ko nikalo aur add kardo for minimum cost

    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main()
{
    int n = 4;
    int arr[] = {4, 3, 2, 6};
    cout << "Minimum cost is " << minimumCostOfRopes(arr, n);
    return 0;
}