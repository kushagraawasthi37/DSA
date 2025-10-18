#include <iostream>
#include <vector>
using namespace std;
void bruteTar(int arr[], int tar, int n)
{

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == tar)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }

    // printing vector
    for (int ele : ans)
    {

        cout << ele << " ";
    }
}

void optimalTar(int arr[], int n, int tar)
{
    int i = 0;
    int j = n - 1;
    vector<int> ans;
    while (i<j)
    {

       if (arr[i]+arr[j]<tar)
       {
        i++;
       }

       if (arr[i]+arr[j]>tar)
       {
        j--;
       }
       if (arr[i]+arr[j]==tar)
       {
        ans.push_back(arr[i]);
        ans.push_back(arr[j]);
        i++;
        j--;
       }
       
       
    }
    
    for (int ele : ans)
    {

        cout << ele << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 6,7};
    int n = 6;
    int tar = 10;
    // Brute force approach
    // bruteTar(arr, n, tar);

    // Optimal approach
    optimalTar(arr,n,tar);

    return 0;
}