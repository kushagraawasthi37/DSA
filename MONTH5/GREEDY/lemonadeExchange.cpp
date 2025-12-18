#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /* Function to find whether each customer can
       be provided with correct change */
    bool lemonadeChange(vector<int> &bills)
    {

        // Counter for $5
        int five = 0;

        // Counter for $10
        int ten = 0;

        // Iterate through each customer's bill
        for (int i = 0; i < bills.size(); i++)
        {

            /* If the customer's
               bill is $5 */
            if (bills[i] == 5)
            {

                // Increment $5
                five++;
            }

            /* If the customer's
               bill is $10 */
            else if (bills[i] == 10)
            {

                /* Check if there are $5
                   bills available to give change */
                if (five)
                {
                    // Use one $5
                    five--;
                    // Receive one $10
                    ten++;
                }

                /* If no $5 bill
                   available, return false */
                else
                    return false;
            }

            /* If the customer's
               bill is $20 */
            else
            {
                /* Check if there are both
                   $5 and $10 bills
                   available to give change */
                if (five && ten)
                {
                    // Use one $5
                    five--;
                    // Use one $10
                    ten--;
                }
                /* If there are not enough $10 bills,
                   check if there are at least
                   three $5 bills available */
                else if (five >= 3)
                {
                    // Use three $5 bills
                    five -= 3;
                }
                /* If unable to give
                   change, return false */
                else
                    return false;
            }
        }

        // Return true
        return true;
    }
};

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for (int bill : bills)
    {
        cout << bill << " ";
    }
    cout << endl;
    Solution solution;
    bool ans = solution.lemonadeChange(bills);
    if (ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}
