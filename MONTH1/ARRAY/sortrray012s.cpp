#include <iostream>
using namespace std;

void sortArray(int arr[], int n)
{
    int countOfZero = 0;
    int countOfOne = 0;
    int countOfTwo = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0)
        {
            countOfZero++;
        }
        if (arr[i] == 0)
        {
            countOfOne++;
        }
        if (arr[i] == 2)
        {
            countOfTwo++;
        }
    }

    int idx = 0;
    for (int i = 0; i < countOfZero; i++)
    {
        arr[idx] = 0;
        idx++;
    }
    for (int i = 0; i < countOfOne; i++)
    {
        arr[idx] = 1;
        idx++;
    }
    for (int i = 0; i < countOfTwo; i++)
    {
        arr[idx] = 2;
        idx++;
    }
}

void DutchNationalFlagAlgo(int arr[], int n)
{
    int mid = 0;
    int low = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // 1st part case
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        if (arr[mid] == 1)
        {
            // 2nd part case
            mid++;
        }
        if (arr[mid] == 2)
        {
            // 3rd part case
            swap(arr[high], arr[mid]);
            high--;
        }
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
    // Largest element at last in every iteration
    int arr[] = {0, 1, 0, 2, 1};
    sortArray(arr, 5);
    printArray(arr, 5);
    DutchNationalFlagAlgo(arr, 5);
    cout << "Dutch National Flag Algorithm " << endl;
    printArray(arr, 5);
    return 0;
}