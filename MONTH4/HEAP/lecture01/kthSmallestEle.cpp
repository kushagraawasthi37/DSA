#include <bits/stdc++.h>
using namespace std;

int kthSmallestEle(int arr[], int k, int n)
{
    // Step 1: start ke k element ka max heap bna diya
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // Step 2: agar aage koi element array mai top element se chota hai to wo aajyega to top remove krdege isse last mai heap mai smallest k element bachege

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3:
    int ans = pq.top();
    return ans;
}
int main()
{
    int arr[] = {7, 10, 4,  20, 15};
    int k =3;
    int n =5;

   cout<<k<<"th smallest element is "<< kthSmallestEle(arr,k,n)<<endl;
   //For Largest element minHeap ka use krke nikal denge
    return 0;
}