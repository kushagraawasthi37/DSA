#include <deque>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// Minimum Element at back of queue
vector<int> slidingWindowMinimumBack(vector<int> &vec, int k)
{
    deque<int> dq;
    vector<int> ans;

    //  first Window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && vec[dq.front()] > vec[i])
        {
            dq.pop_front();
        }
        dq.push_front(i);
    }

    // for rest of window
    for (int i = k; i < vec.size(); i++)
    {

        ans.push_back(vec[dq.back()]);

        // Remove the element that are not part of current window
        while (!dq.empty() && dq.back() <= i - k)
        {
            dq.pop_back();
        }

        // check the Current window minimum
        while (!dq.empty() && vec[dq.front()] > vec[i])
        {
            dq.pop_front();
        }
        dq.push_front(i);
    }

    ans.push_back(vec[dq.back()]);

    return ans;
}

// Minimum Element at Front of queue
vector<int> slidingWindowMinimumfront(vector<int> &vec, int k)
{
    deque<int> dq;
    vector<int> ans;

    //  first Window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && vec[dq.back()] > vec[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // for rest of window
    for (int i = k; i < vec.size(); i++)
    {

        ans.push_back(vec[dq.front()]);

        // Remove the element that are not part of current window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // check the Current window minimum
        while (!dq.empty() && vec[dq.back()] > vec[i])
        {
            dq.pop_back();
        }
        
        dq.push_back(i);
    }

    ans.push_back(vec[dq.front()]);

    return ans;
}

int main()
{
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Minimum element in subarray of size " << k << " sliding Window Minimum  at Back of queue " << endl;
    vector<int> result = slidingWindowMinimumBack(vec, k);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << "\nMinimum element in subarray of size " << k << " sliding Window Minimum  at Front of queue " << endl;

    vector<int> result2 = slidingWindowMinimumfront(vec, k);
    for (int val : result2)
    {
        cout << val << " ";
    }

    cout << endl;
}