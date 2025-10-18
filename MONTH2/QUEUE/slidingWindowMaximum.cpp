#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &vec, int k)
{

    // DEQUE(IDX KO STORE KARNEGE)
    // 0.DEQUE FRONT ALL ELEMENT MUST BE CURRENT WINDOW PART (IDX(DQ.FRONT())<= I-K)
    // 1.CURELEMENT>=DEQUE ELE THEN USKO HTA DO KYUKI WO KABHI VIABLE ANSWER NHI BAN SKTA
    // WE DECIDED TO GET THE MAXIIMUM VALUE AT FRONT OF DEQUE(DESCENDING ORDER IN DEQUE)
    
    vector<int> ans;
    deque<int> dq;

    // ANALYSE THE FIRST WINDOW
    for (int i = 0; i < k; i++)
    {
        // 1.CURRENT ELEMENT>=DEQUE ELE THEN USKO HTA DO KYUKI WO KABHI VIABLE ANSWER NHI BAN SKTA

        while (dq.size() > 0 && vec[dq.back()] <= vec[i])
        {
            dq.pop_back();
            // DECREASING ORDER MUST MAINTAIN
        }
        // adding element if needed;
        dq.push_back(i);
    }

    // ANALYSE FOR THE REMAINING WINDOW

    for (int i = k; i < vec.size(); i++)
    {
        // OLD WINDOW KA ANSWER STORE KARENGE
        ans.push_back(vec[dq.front()]);

        // remove element not part of cuurent window
        while (dq.size() > 0 && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // remove the smaller value from the end
        while (dq.size() > 0 && vec[dq.back()] < vec[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // ADDING RESULT OF LAST WINDOW
    ans.push_back(vec[dq.front()]);

    return ans;
}

int main()
{
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "SLIDING WINDOW MAXIMUM:\n";
    vector<int> result = slidingWindowMaximum(vec, k);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}