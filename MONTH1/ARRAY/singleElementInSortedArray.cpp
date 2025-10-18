#include <iostream>
using namespace std;


int singleElementInSortedArray(int arr[], int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        // Every non -single element start at even index and end at odd index -> 
        // Ensure mid is even->
        if (mid % 2 == 1)
            mid--;

        // If pair is valid, move to right
        if (arr[mid] == arr[mid + 1])
            s = mid + 2;
        else
            e = mid;
    }

    return arr[s];
}
int main()
{
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single Element in sorted Array " << singleElementInSortedArray(arr, 9);
    return 0;
}