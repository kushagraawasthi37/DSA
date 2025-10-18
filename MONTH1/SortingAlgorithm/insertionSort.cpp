#include <iostream>
using namespace std;

void insertionSortAsce(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i];
        int prev = i - 1;
        // 4,1,5,2,3
        while (prev >= 0 && cur < arr[prev])
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = cur;
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

    int arr[] = {4, 1, 5, 2, 3};
    insertionSortAsce(arr, 5);
    printArray(arr, 5);
    return 0;
}