#include <iostream>
using namespace std;
void change(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * 2;
    }
}
int main()
{
    int a[2];
    int b[100] = {1, 2, 3, 4};
    int c[] = {1, 2, 3, 4};

    cout << c[0] << endl;

    // Length of array
    // int size = sizeof(a) / sizeof(a[0]);
    // cout << size << endl;

    // Loops in array

    // for loop
    // for (int i = 0; i < size; i++)
    // {
    //     cout << b[i];
    // }

    // input using loop
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> a[i];
    // }

    // Array always passed by reference array name is an pointer

    change(c, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}