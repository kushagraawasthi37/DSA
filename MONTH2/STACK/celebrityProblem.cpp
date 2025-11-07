#include <bits/stdc++.h>
using namespace std;
int celebrityProblemBrute(vector<vector<int>> &person)
{
    // BRUTE FORCE APPROACH
    for (int cele = 0; cele < person[0].size(); cele++)
    {
        bool isCele = true;
        for (int normal = 0; normal < person.size(); normal++)
        {

            if (normal == cele)
                continue;

            // Koi person agar celebrity ko nhi janta ya celcebrity agar kisi person ko janta hai
            if (person[normal][cele] != 1 || person[cele][normal] != 0)
            {
                isCele = false;
                break;
            }
        }
        if (isCele)
            return cele;
    }
    return -1;
}

int celebrityProblem(vector<vector<int>> &person)
{
    // TC->O(n);
    // SC->O(n);

    int n = person.size();
    stack<int> s;

    // Step 1: Add everyone in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Check For celebrity
    //  Step 2: Eliminate until one remains
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (person[a][b] == 0)
        {
            s.push(a); // b Can not be celebrity
        }
        else
        {
            s.push(b); // a can not be celebrity
        }
    }

    int cele = s.top();//Potential celebrity
    for (int i = 0; i < n; i++)
    {
        if ((i != cele) && (person[cele][i] == 1 || person[i][cele] == 0))
            return -1;
    }
    return cele;
}
int main()
{
    vector<vector<int>> person{{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << "Brute: " << celebrityProblemBrute(person) << endl;
    cout << "Optimal: " << celebrityProblem(person) << endl;

    return 0;
}