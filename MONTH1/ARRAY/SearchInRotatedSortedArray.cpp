#include <iostream>
using namespace std;

int binarySearchInRotatedSortedArray(int arr[], int tar, int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // Correct answer is found
        if (tar == arr[mid])
        {
            return mid;
        }

        // Left part is sorted
        if (arr[s] <= arr[mid])
        {
            // Answer lies in sorted Left part
            if (arr[s] <= tar && tar <= arr[mid])
            {
                e = mid - 1;
            }
            // Answer does not exist in this sorted part
            else
            {
                s = mid + 1;
            }
        }

        // Right part is sorted
        else if (arr[e] >= arr[mid])
        {
            if (arr[mid] <= tar && tar <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    // Sorted and target then always try to think about the binary search algorithm
    // In Rotated sorted array one part left or right is always sorted usi mai binary search lagyenge

    // for Left half sorted means arr[s]<=arr[mid]
    // for Right half sorted means arr[e]>=arr[mid]

    int arr[] = {3, 4, 5, 6, 7, 0, 1, 2};
    cout << "index of target Elemnt " << binarySearchInRotatedSortedArray(arr, 9, 8);
    return 0;
}