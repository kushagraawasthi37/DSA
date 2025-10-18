#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator to compare concatenated strings
static bool myCompare(string &s1, string &s2)
{
    return (s1 + s2) > (s2 + s1);
}

// Function to return the largest concatenated number
string findLargest(vector<int> &arr)
{

    vector<string> numbers;
    for (int ele : arr)
    {
        numbers.push_back(to_string(ele));
    }

    // Sort the array using the custom comparator
    sort(numbers.begin(), numbers.end(), myCompare);

    // Handle the case where all numbers are zero.
    // We are sorting is descending order, so zero
    // in front means complete array contains zero
    if (numbers[0] == "0")
    {
        return "0";
    }

    // Concatenate the sorted array
    string res = "";
    for (string &num : numbers)
    {
        res.append(num);
    }

    return res;
}

int main()
{
    vector<int> arr = {3, 30, 34, 5, 9};
    cout << findLargest(arr) << endl;
    return 0;
}