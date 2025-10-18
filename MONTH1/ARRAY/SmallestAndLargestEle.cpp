#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 3, 4, 7, 5};

    int smallest = INT16_MAX;
    int largest = 0;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    cout << "largest element " << largest << endl;
    cout << "Smallest " << smallest << endl;

    return 0;
}