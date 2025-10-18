#include <iostream>
#include <limits.h>
using namespace std;

// buy and sell stock -> maximum profit

// Solution by me
int stockBuySell(int arr[], int n)
{
    int maxprofit = 0;

    for (int i = 0; i < n; i++)
    {
        int profit = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            int curprofit = arr[i] - arr[j];
            if (curprofit > profit)
            {
                profit = curprofit;
            }
        }
        maxprofit = max(profit, maxprofit);
    }

    return maxprofit;
}

// Solution by Mam

int stockProfit(int arr[], int n)
{

    int bestBuy = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int currProfit = 0;
        if (arr[i] < bestBuy && i != n - 1 /*Last day can not be buy day*/)
        {
            bestBuy = arr[i]; // Stock-> Lowest price Day
        }
        
        currProfit = arr[i] - bestBuy;
        maxProfit = max(currProfit, maxProfit);
    }

    return maxProfit;
}

int main()
{
    int arr[] = {7, 8, 1, 5, 6, 0};
    cout << "max Profit By me" << stockBuySell(arr, 6) << endl;
    cout << "max Profit By Mam  " << stockProfit(arr, 6) << endl;
    return 0;
}