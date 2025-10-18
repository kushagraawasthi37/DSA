#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            return mid;
        }

        mid = s + (e - s) / 2;
    }

    return -1;

    // Time complexity of binary Search is logn
}

int binarySearchUsingReccursion(int arr[], int s, int e, int target)
{
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > target)
        {
            return binarySearchUsingReccursion(arr, s, mid - 1, target);//left Half
        }
        if (arr[mid] < target)
        {
            return binarySearchUsingReccursion(arr, mid + 1, e, target);//Right half
        }
    }

    return -1;
}

int main()
{
    // Always work in sorted array
    // find mid element
    // go to left array if target is less than middle
    // go to right array if target is greater than middle

    int arr[] = {0, 1, 3, 5, 7, 10};
    int target = 7;
    cout << "Index of Target Element " << binarySearch(arr, 6, target) << endl;
    cout << "Index of Target Element by Recursive Binary Search " << binarySearchUsingReccursion(arr, 0, 5, 20);
    return 0;
}