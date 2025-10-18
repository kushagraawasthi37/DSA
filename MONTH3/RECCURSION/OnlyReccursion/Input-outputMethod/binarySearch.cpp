#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[], int s, int e, int target)
{

    int mid = s + (e - s) / 2;

    if (s < e)
    {
        if (arr[mid] == target)
            return true;

        if (arr[mid] < target)
            binarySearch(arr, mid + 1, e, target);

        else if (arr[mid] > target)
            binarySearch(arr, s, mid - 1, target);
    }

    // Till Now element not found
    return false;
}
int main()
{
    int arr[] = {1, 2, 34, 45, 234};
    cout << binarySearch(arr, 0, 4, 34);
    return 0;
}