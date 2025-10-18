#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void intersection(int arr1[], int arr2[], int s1, int s2)
{
    unordered_set<int> set1;
    unordered_set<int> result;

    // Insert all elements of arr1 into set1
    for (int i = 0; i < s1; i++)
    {
        set1.insert(arr1[i]);
    }

    // Check each element of arr2
    for (int i = 0; i < s2; i++)
    {
        if (set1.find(arr2[i]) != set1.end())
        {
            result.insert(arr2[i]); // automatically handles duplicates
        }
    }

    cout << "Intersection: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}

int unique(int arr[], int size)
{
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (m[arr[i]] == 1)
        {
            cout << "Unique" << arr[i] << endl;
        }
    }

    return -1;
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 6, 7};
    int arr[] = {1, 3, 4, 5};

    int arr2[] = {1, 2, 3, 4, 1, 2, 3};

    intersection(arr, arr1, 5, 7);
    unique(arr2, 7);

    return 0;
}