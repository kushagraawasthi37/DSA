#include <iostream>
#include <vector>
using namespace std;

int maxAmount(vector<int> house)
{
    // TC->O(n)
    // SC->O(1)
    
    int n = house.size();
    if (n == 0)
        return 0;

    if (n == 1)
        return house[0];

    int prevHouse2 = house[0];
    int prevHouse1 = max(house[1], house[0]);

    int currHouse;
    for (int i = 2; i < n; i++)
    {
        // Picked
        int pick = prevHouse2 + house[i];
        // not Picked
        int Notpick = prevHouse1;

        currHouse = max(pick, Notpick);
        prevHouse2 = prevHouse1;
        prevHouse1 = currHouse;
    }
    return prevHouse1;
}

int main()
{
    vector<int> houses = {9, 9, 8, 2};

    cout << "Max amount that can be robbed: " << maxAmount(houses) << endl;
    return 0;
}