class Solution {

private:
    bool isPalindrome(string s, int i, int j, bool& taken) {

        while (i < j) {

            if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
            } else if (!taken) {
                taken = true;
                return isPalindrome(s, i + 1, j, taken) ||
                       isPalindrome(s, i, j - 1, taken);
            } else
                return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        bool taken = false;
        return isPalindrome(s, 0, s.length() - 1, taken);
    }
};