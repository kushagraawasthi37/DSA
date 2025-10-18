#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e, int mid)
{
    int i = s, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= e)
    {
        if (arr[i] > arr[j])
        {
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx+s] = temp[idx];
    }

    return;
}
void MergeSort(int arr[], int s, int e)
{

    // DIVIDE AND CONQURER
    // DIVIDE THE ARRAY
    // MERGE PARTS TO CREATE A SORTED ARRAY(BACKTRACKING)

    // DIVIDE THE ARRAY
    if (s <e)
    {
        int mid = s + (e - s) / 2;

        // LEFT PART
        MergeSort(arr, s, mid);

        // RIGHT PART

        MergeSort(arr, mid + 1, e);

        // MERGE THE DIVIDED ARRAY
        merge(arr, s, e, mid);
    }
}
int main()
{
    int arr[] = {12, 31, 35, 8, 32, 17};
    MergeSort(arr, 0, 5);
    for (int i = 0; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}