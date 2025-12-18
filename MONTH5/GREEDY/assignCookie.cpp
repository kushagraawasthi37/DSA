#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the maximum number of content children
    int findMaximumCookieStudents(vector<int> &Student, vector<int> &Cookie)
    {
        int n = Student.size();
        int m = Cookie.size();
        // Pointers
        int l = 0, r = 0;
        // Sorting of vectors
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        // Traverse through both arrays
        while (l < n && r < m)
        {
            /*If the current cookie can satisfy
            the current student, move to the
            next student*/
            if (Cookie[r] >= Student[l])
            {
                l++;
            }
            // Move to next cookie
            r++;
        }
        // Return the number of students who got cookies
        return l;
    }
};
int main()
{
    // Example input
    vector<int> Student = {1, 2};
    vector<int> Cookie = {1, 2, 3};

    // Create a Solution object
    Solution solution;

    // Call the findMaximumCookieStudents function
    int result = solution.findMaximumCookieStudents(Student, Cookie);

    // Output the result
    cout << "Number of students satisfied: " << result << endl;

    return 0;
}
