#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int tar)
{
    for (int i = 0; i < size; i++)
    {
        if (tar == arr[i])
        {
            cout << "Element present " << endl;
            return 1;
        }
    }
    cout<<"Element not present "<<endl;
    return 0;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    linearSearch(arr, 5, 6);
    return 0;
}