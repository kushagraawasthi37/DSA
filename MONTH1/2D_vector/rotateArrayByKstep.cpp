#include <algorithm>
#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    // Print the rotated array
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateArrayOpt(int arr[], int n, int k)
{

    // Ensure k is within bounds
    k = k % n;

    // Create an auxiliary array for rotation
    int arr2[n];

    // Rotate the elements
    for (int i = 0; i < n; i++)
    {
        int tp = (i + k) % n;       // Compute the new index
        arr2[(i + k) % n] = arr[i]; // Place element in the new index
    }

    // Copy the rotated array back to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }

    printArray(arr, n);
}
void rotateArray(int arr[], int k, int n)
{

    // MY APPROACH

    // 1 2 3 4 5
    // 4 5 1 2 3

    k = k % n;

    int arr2[n];
    int temp = 0;
    for (int i = k; i < n; i++)
    {
        arr2[i] = arr[temp];
        temp++;
    }

    temp = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        arr2[i] = arr[temp];
        temp--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
    cout << endl;
    printArray(arr, n);
}

void rotateArrayCW(int arr[], int k, int n)
{
    k = k % n;
    int arr2[n];
    int j = 0;

    for (int i = n - k; i < n; i++)
    {
        arr2[j] = arr[i];
        j++;
    }

    for (int i = 0; i < n - k; i++)
    {
        arr2[j] = arr[i];
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
    cout << endl;
    printArray(arr, n);
}

void reverseArray(int arr[], int i, int j)
{
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void rotateArrayCWithoutExtraSpace(int arr[], int k, int n)
{
    k = k % n;
    reverseArray(arr, 0, n - k - 1);
    reverseArray(arr, n - k, n - 1);
    reverseArray(arr, 0, n - 1);

    printArray(arr, n);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k = 2;
    int n = 5;

    // Rotate the array
    cout << "Rotation Approach By Love babbar " << endl;
    rotateArrayOpt(arr, n, k);
    cout << "Rotation Approach By me " << endl;
    rotateArray(arr, k, n);
    cout << "Rotation approach by college wallah " << endl;
    rotateArrayCW(arr, k, n);
    cout << "Rotation approach by college wallah without extra space " << endl;
    rotateArrayCWithoutExtraSpace(arr, k, n);

    return 0;
}
