#include <iostream>
#include <vector>
using namespace std;

void segregateElements(vector<int> &arr)
{
    // Your code goes here

    vector<int> posi;
    vector<int> nega;

    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] >= 0)
            posi.push_back(arr[i]);
        else
        {
            nega.push_back(arr[i]);
        }
        i++;
    }

    for (int i = 0; i < posi.size(); i++)
    {
        arr[i] = posi[i];
    }
    int idx = 0;
    for (int i = posi.size(); i < arr.size(); i++)
    {
        arr[i] = nega[idx++];
    }
}
int main()
{
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    segregateElements(arr);
     for (auto ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}