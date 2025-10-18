#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArray(vector<vector<int>> &arr, int k)
{
    // TC-> O(nlogk)
    // SC-> O(k)

    priority_queue<node *, vector<node *>, compare> minheap;

    // step1: sarre arrays ke first element ko insert krna hai
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        minheap.push(temp);
    }

    vector<int> ans;

    // step2:
    while (minheap.size() > 0)
    {
        node *temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        int i = temp->row;
        int j = temp->col;

        // Smallest element jis array ka hai uske aage ke element bhi check karlo agar ho to
        if (j + 1 < arr[i].size())
        {
            node *next = new node(arr[i][j + 1], i, j + 1);
            minheap.push(next);
        }

        delete temp;
    }
    return ans;
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {3, 4, 5}, {2, 5, 7}};
    vector<int> ans = mergeKSortedArray(vec, 3);

    for (int ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}