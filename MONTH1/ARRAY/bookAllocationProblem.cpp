#include <iostream>
using namespace std;

bool isValid(int arr[], int maxAllowedPage, int n, int student)
{
    int tempStu = 1;
    int curPage = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPage)
        {
            return false;
        }

        if (curPage + arr[i] <= maxAllowedPage)
        {
            curPage += arr[i];
        }
        else
        {
            //Incraese student
            tempStu++;
            
            if (tempStu > student)
            {
                return false;
            }

            // Assign For new Student
            curPage = arr[i];
        }
    }

    return true;
}

int minMaxPages(int arr[], int n, int student)
{
    int totalPage = 0;
    for (int i = 0; i < n; i++)
    {
        totalPage += arr[i];
    }
    int s = 0;
    int e = totalPage;
    int ans;


    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isValid(arr, mid, n, student))
        {
            // Left mai jao
            ans = mid; // Mid se jadha bhi valid answwer hi hoga to kam mai dekh ke aur minimise karo
            e = mid - 1;
        }
        else
        { // right mai jao
            s = mid + 1;
        }
    }

    return ans;
}
int main()
{
    int arr[] = {40, 30, 10, 20};
    cout << "Maximum allowed page is minimum " << minMaxPages(arr, 4, 2);
    return 0;
}