#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
private:
    int K;                                             // Integer K
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

public:
    // Constructor
    KthLargest(int k, vector<int> &nums)
    {
        K = k; // Initialize the integer

        // Traverse all the elements in the array
        for (int i = 0; i < nums.size(); i++)
        {
            // If the size of min-heap is less than k
            if (pq.size() < K)
                pq.push(nums[i]); // Add the current element

            // Else if the top element is smaller than the current element
            else if (nums[i] > pq.top())
            {
                pq.pop();         // Pop the top element
                pq.push(nums[i]); // Add the current element
            }
        }
    }

    int add(int val)
    {
        // If the size of the queue is less than K
        if (pq.size() < K)
        {
            pq.push(val);

            return pq.top();
        }

        // If the smallest element is less than the element to be added
        if (val > pq.top())
        {
            pq.pop();     // Remove the top element
            pq.push(val); // Add the current element
        }

        return pq.top(); // Return the Kth largest element
    }
};

// Driver code
int main()
{
    int k = 3;
    vector<int> nums = {1, 2, 3, 4};

    // Creating an object of KthLargest class
    KthLargest kthLargest(k, nums);

    // Performing different operations
    cout << "Kth Largest element after adding 5 is: " << kthLargest.add(5) << endl;
    cout << "Kth Largest element after adding 2 is: " << kthLargest.add(2) << endl;
    cout << "Kth Largest element after adding 7 is: " << kthLargest.add(7) << endl;

    return 0;
}