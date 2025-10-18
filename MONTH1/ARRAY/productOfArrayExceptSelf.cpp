#include <iostream>
#include <vector>
using namespace std;

// BruteForceApproach By Me
void BFAProductOfArrayExceptSelf(vector<int> &vec)
{
    int n = vec.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        double tempele = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                tempele *= vec[j];
            }
        }
        ans.push_back(tempele);
    }
    for (int ele : ans)
    {
        cout << ele << " ";
    }
}

// Handle only if there is 1 zero  in arr
void oAProductOfArrayExceptSelf(int arr[], int n)
{ // linear space complexity
    int prefix_pro[n];
    int suffix_pro[n];

    prefix_pro[0] = 1;
    suffix_pro[n - 1] = 1;

    // Calculate prefix product
    for (int i = 1; i < n; i++)
    {
        prefix_pro[i] = prefix_pro[i - 1] * arr[i - 1];
    }

    // Calculate Suffix product
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_pro[i] = suffix_pro[i + 1] * arr[i + 1];
    }

    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix_pro[i] * suffix_pro[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

// Handle only if there is 1 zero  in arr
void oAProductOfArrayExceptSelfConstantSpace(int arr[], int n)
{
    // constant space space complexity
    int suffix_pro = 1;
    vector<int> ans(n, 1);

    // Calculate Prefix product
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * arr[i - 1];
    }

    // Calculate the Suffix Product
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_pro *= arr[i + 1];
        ans[i] *= suffix_pro;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

vector<int> bestProductOfArrayExceptSelf(int arr[], int n)
{
    int zeroCount = 0;
    int totalProduct = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zeroCount++;
        else
        {
            totalProduct *= arr[i];
        }
    }

    vector<int> ans(n, 0);

    if (zeroCount > 1)
    {
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        if (zeroCount == 0)
        {
            ans[i] = totalProduct / arr[i];
        }
        else if (arr[i] == 0)
        {
            ans[i] = totalProduct; // Product exist for only 0-element 
        }
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    int arr[] = {1, 2, 0, 4};
    int arr1[] = {1, 0, 0, 4};
    BFAProductOfArrayExceptSelf(vec);
    cout << endl;

    oAProductOfArrayExceptSelf(arr1, 4);
    oAProductOfArrayExceptSelfConstantSpace(arr1, 4);
    cout << endl;
    vector<int> ans = bestProductOfArrayExceptSelf(arr1, 4);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
