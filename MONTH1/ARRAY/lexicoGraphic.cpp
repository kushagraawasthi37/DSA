#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextLexicographic(vector<int> &arr)
{
    // Find the pivot element->arr[i]<arr[i+1];
    // RightMost element > pivot -> swap(rightmost,pivot)
    // reverse (pivot+1) to n-1 element

    int piv = -1;
    int n = arr.size();

    // Step 1:Find pivot
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            piv = i;
            break;
        }
    }

    // Sare element decreasing order mai pade hai
    if (piv == -1)
    {
        reverse(arr.begin(), arr.end());
        return; // MUST return here
    }

    // Step 2:Find Rightmost Successor
    for (int i = n - 1; i > piv; i--)
    {
        if (arr[i] > arr[piv])
        {
            swap(arr[i], arr[piv]);
            break;
        }
    }

    // Step 3: Reverse the array from pivot +1 to end
    reverse(arr.begin() + piv + 1, arr.end());
}

void printArray(vector<int> vec)
{
    for (int ele : vec)
    {
        cout << ele << " ";
    }
}
int main()
{

    vector<int> vec = {1, 2, 5, 4, 3};
    nextLexicographic(vec);
    printArray(vec);
    return 0;
}