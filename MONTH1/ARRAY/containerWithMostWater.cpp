#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Brute force approach By me
int bFAContainerWithMostWater(int arr[], int n)
{
    int maxarea = INT8_MIN;
    int area;
    for (int lb = 0; lb < n; lb++)
    {
        int width = 1;

        for (int rb = lb + 1; rb < n; rb++)
        {

            int height = min(arr[lb], arr[rb]);
            area = height * width;
            maxarea = max(area, maxarea);
            width++;
        }
    }
    return maxarea;
}

// Optimal approach 2pointer approach

int oAContainerWithMostWater(int container[], int n)
{
    int leftBoundary = 0;
    int rightBoundary = n - 1;
    int maxwater = 0;

    while (leftBoundary < rightBoundary)
    {
        // Calculate current water
        int height = min(container[leftBoundary], container[rightBoundary]);
        int width = rightBoundary - leftBoundary;
        int currWater = height * width;

        // Update maxWater
        maxwater = max(currWater, maxwater);

        if (container[leftBoundary] < container[rightBoundary])
        {
            leftBoundary++;
        }
        else
        {
            rightBoundary--;
        }
    }
    return maxwater;
}
int main()
{
    int arr[] = {1, 8, 6, 2, 4, 5, 8, 3, 7};
    cout << "container with most water by Brute Force approach" << bFAContainerWithMostWater(arr, 9) << endl;
    cout << "container with most water by Optimal solution " << oAContainerWithMostWater(arr, 9) << endl;
    return 0;
}