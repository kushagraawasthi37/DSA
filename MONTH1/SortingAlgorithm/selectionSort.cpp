#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // 4 1 5 2 3
        int smallestidx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallestidx] > arr[j])
            {
                smallestidx = j;
            }
        }
        swap(arr[i], arr[smallestidx]);
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
    // Smallest element at start in every iteration
    int arr[] = {4, 1, 5, 2, 3};
    selectionSort(arr, 5);
    printArray(arr, 5);
    return 0;
}