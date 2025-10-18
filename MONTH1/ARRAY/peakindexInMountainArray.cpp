#include <iostream>
using namespace std;

// Only single peak exist
int peakIndexInMountainArray(int arr[], int n)
{                  // some Constarint
    int s = 1;     // first element kabhi peak nhi hoga
    int e = n - 2; // Last elemnt bhi peak nhi hoga
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] < arr[mid - 1])
        {
            e = mid - 1; // Decresing side par hai mid
        }
        else
        {
            s = mid + 1; // Increasing side par hai mid
        }
    }

    return -1;
}

// multiple peak can exists

int findPeakElement(int arr[], int n)
{
    if (n == 1)
        return arr[0]; // Only one element, it's the peak

    if (arr[0] > arr[1])
        return arr[0]; // Peak at start

    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1]; // Peak at end

    int s = 1, e = n - 2; // Search between, as ends are already checked

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // Check if mid is a peak
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
            return arr[mid];

        // Move towards the greater neighbor
        else if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    // Fallback (should never happen if input has at least one peak)
    return -1;
}

int main()
{
    int arr[] = {0, 3, 8, 9, 5, 2};
    cout << "Peak Element " << peakIndexInMountainArray(arr, 6);

    return 0;
}