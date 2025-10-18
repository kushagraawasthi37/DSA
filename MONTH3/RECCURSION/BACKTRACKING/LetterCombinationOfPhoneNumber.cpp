#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursive function to generate letter combinations
    void func(int ind, string input, string &temp, vector<string> &ans, string combos[]) {
        // Base case: if index reaches the end of digits
        if(ind == input.size()) {
            // Add the current combination to the answer
            ans.push_back(temp);
            return;
        }

        // Convert the current character to an integer
        int digit = input[ind] - '0';
        // Loop through the corresponding characters
        for(int i = 0; i < combos[digit].size(); i++) {
            // Recursively call function with next index
            // Add current character to the string
            temp.push_back(combos[digit][i]);
            func(ind + 1, input, temp, ans, combos);
            temp.pop_back();
        }
    }

public:
    // Function to get all letter combinations for a given digit string
    vector<string> letterCombinations(string digits) {
        // Mapping digits to corresponding characters
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; // Vector to store results
        string output = ""; // Temporary string to build combinations
        // Initiate recursive function
        func(0, digits, output, ans, combos);
        return ans; // Return the result
    }
};

int main() {
    Solution solution;
    string digits = "232"; // Input digits
    vector<string> result = solution.letterCombinations(digits); // Get combinations

    // Print the results
    for (const string& combination : result) {
        cout << combination << " ";
    }
    return 0;
}
