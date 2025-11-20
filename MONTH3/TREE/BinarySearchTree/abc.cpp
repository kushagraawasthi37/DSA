#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> vec)
{
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void heapify(vector<int> &nums, int ind, int val)
{
    nums[ind] = val;
    while (ind >= 0)
    {
        printArr(nums);
        double parent = ind / 2.0;
        parent = ceil(parent) - 1;

        cout << "Index " << ind << endl;
        cout << "Parent " << parent << endl;

        if (nums[parent] <= nums[ind])
        {
            return;
        }
        else
        {
            swap(nums[parent], nums[ind]);
            ind = parent;
        }
    }

    printArr(nums);
}

int main()
{
    vector<int> vec = {1, 4, 5, 5, 7, 6};
    heapify(vec, 5, 2);
    return 0;
}