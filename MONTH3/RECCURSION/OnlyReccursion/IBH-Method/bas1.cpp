#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Reccursion function call itself

// TIME COMPLEXITY OF RECUSRION FUNCTION
//  1.USING RECUURENCE RELATON
// 2.TC=TOTAL RC +WORK IN EACH RC

// SPACE COMPLEXITY
// SC =HEIGHT OF CALL STACK*MEMORY IN EACH CALL

// TRY TO WRITE BASE CASE IN START OF FUNCTION

// JAB BASE CASE MAI RETURN HOTA HAI TAB HUM BACK AA JATE HAI USE HUM BACKTRACK BOLTE HAI

void printNumber(int n)
{

    // SEARCH SMALL PROBLEM
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    printNumber(n - 1);
}

int factorial(int n)
{
    // Base case
    if (n == 1)
    {
        return 1;
    }

    // Sub problem
    //  n!=n*(n-1)!

    return n * factorial(n - 1);
}

int sum(int n)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    // sub Problem
    return n + sum(n - 1);
}

int main()
{
    printNumber(100);
    cout << factorial(6) << endl;
    cout << sum(10);
    return 0;
}