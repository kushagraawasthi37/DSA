#include <iostream>
using namespace std;
void reverse(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    while (s < e)
    {
        swap(arr[e--], arr[s++]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    reverse(arr, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}