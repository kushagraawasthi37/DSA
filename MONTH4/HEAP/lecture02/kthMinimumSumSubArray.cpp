#include <bits/stdc++.h>
using namespace std;
int kthSmallestSumSubArray(vector<int> &vec, int k)
{
    priority_queue<int> maxheap;
    for (int i = 0; i < vec.size(); i++)
    {

        int sum =0;
        for (int j = i; j < vec.size(); j++)
        {
            sum += vec[j];

            if (maxheap.size() < k)
            {
                maxheap.push(sum);
            }
            else
            {
                if (maxheap.top() > sum)
                {
                    maxheap.pop();
                    maxheap.push(sum);
                }
            }
        }
    }

    return maxheap.top();
}
int main()
{
    vector<int> vec={1,2,7,4,5};
   cout<< kthSmallestSumSubArray(vec,2);
    return 0;
}