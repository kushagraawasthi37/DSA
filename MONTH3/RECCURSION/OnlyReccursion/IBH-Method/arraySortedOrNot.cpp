#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n)
{
    // TC-> O(n)
    // SC->O(n)

    // BASE CASE
    if (n == 1 || n == 0)
        return true; // Single element or 0 element array is always sorted

    // Check Sorted in Increasing order
    if (arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1))
        return true;

    // Decresing order sorted
    if ((arr[n - 1] <= arr[n - 2]) && isSorted(arr, n - 1))
        return true;

    return false;
}
int main()
{
    int arr[] = {1233, 232, 124, 34, 3, 1};
    int n = 6;
    cout << isSorted(arr, n) << endl;
    return 0;
}