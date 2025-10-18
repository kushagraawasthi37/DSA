#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int val, int row, int col)
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

int smallestRangeInKList(vector<vector<int>> &list, int k, int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node *, vector<node *>, compare> minheap;

    for (int i = 0; i < k; i++)
    {
        int ele = list[i][0];
        // Update minimum element
        mini = min(mini, ele);
        // Update maximum element
        maxi = max(maxi, ele);
        minheap.push(new node(ele, i, 0));
    }

    int start = mini, end = maxi;

    //process range
    while ((!minheap.empty()))
    {
        //minium element fetched
        node *temp = minheap.top();
        minheap.pop();

        //range or anser updation
        mini = temp->data;
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }


        //next element exist
        if (temp->col+1 < n)
        {
            maxi = max(maxi, list[temp->row][temp->col + 1]);
            minheap.push(new node(list[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            //Next element does not exist
            break;
        }
    }
    //returning the difference
    return end- start+1;
}
int main()
{
}