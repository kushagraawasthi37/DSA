#include <iostream>
using namespace std;
bool isValidPartition(int arr[], int AllowedTime, int size, int maxPainter)
{

    int curTime = 0;
    int painter = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > AllowedTime)
        {
            return false;
        }

        if (arr[i] + curTime <= AllowedTime)
        {
            curTime += arr[i];
        }
        else
        {
            painter++;
            if (painter > maxPainter)
            {
                return false;
            }
            curTime = arr[i];
        }
    }

    return true;
}
int PainterMinimumTime(int arr[], int painter, int size)
{
    int totalLength = 0;
    for (int i = 0; i < size; i++)
    {
        totalLength += arr[i];
    }

    int s = 0;
    int e = totalLength;

    int ans;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isValidPartition(arr, mid, size, painter))
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {40, 30, 10, 20};
    cout << "Minimum Time To Paint " << PainterMinimumTime(arr, 2, 4);
    return 0;
}