#include <bits/stdc++.h>
using namespace std;

// Without using Extra Space

// koi assumption nahi hai ki array sorted hai general array ke liye working hai
void merge2SortedArray(int arr1[], int arr2[], int m, int n)
{
    // Shift original arr1 elements to the end
    for (int i = m - 1; i >= 0; i--)
    {
        arr1[i + n] = arr1[i];
    }

    int i = n; // Start of shifted arr1
    int j = 0; // arr2 pointer
    int k = 0; // merged position

    while (i < m + n && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            arr1[k++] = arr1[i++];
        }
        else
        {
            arr1[k++] = arr2[j++];
        }
    }

    while (j < n)
    {
        arr1[k++] = arr2[j++];
    }
}

// Function to merge two sorted arrays nums1 and nums2
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // When left in nums1[] and right in nums2[]
            if (left < m && right >= m)
            {
                swapIfGreater(nums1, nums2, left, right - m);
            }
            // When both pointers in nums2[]
            else if (left >= m)
            {
                swapIfGreater(nums2, nums2, left - m, right - m);
            }
            // When both pointers in nums1[]
            else
            {
                swapIfGreater(nums1, nums1, left, right);
            }
            // Increment the pointers by 1 each
            left++, right++;
        }
        // If gap is equal break out of the loop
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }

    // Copy elements of nums2 into nums1
    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - m];
    }
}

// Utility function to swap elements if needed
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int idx1, int idx2)
{
    if (arr1[idx1] > arr2[idx2])
    {
        swap(arr1[idx1], arr2[idx2]);
    }
}


// By Using Extra Space
void mergeSortedArray(int arr1[], int arr2[], int m, int n)
{
    int res[m + n];
    int i = 0, j = 0;
    int idx = 0;

    while (i < m && j < n)
    {
        if (arr1[i] > arr2[j])
        {
            res[idx] = arr2[j];
            idx++;
            j++;
        }
        else
        {
            res[idx] = arr1[i];
            i++;
            idx++;
        }
    }

    // Remaining element of 2nd array
    while (j < n)
    {
        res[idx] = arr2[j];
        idx++;
        j++;
    }

    // remaining element of first array
    while (i < m)
    {
        res[idx] = arr1[i];
        idx++;
        i++;
    }

    // Copy merged result back to arr1
    for (int k = 0; k < m + n; k++)
    {
        arr1[k] = res[k];
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr1[6] = {1, 2, 3};
    int arr2[3] = {2, 5, 6};
    // merge2SortedArray(arr1, arr2, 3, 3);
    mergeSortedArray(arr1, arr2, 3, 3);
    printArray(arr1, 6);
    return 0;
}