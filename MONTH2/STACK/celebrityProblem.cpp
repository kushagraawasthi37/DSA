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

    int cele = s.top(); // Potential celebrity
    for (int i = 0; i < n; i++)
    {
        if ((i != cele) && (person[cele][i] == 1 || person[i][cele] == 0))
            return -1;
    }
    return cele;
}

int celebrity(vector<vector<int>> &M)
{

    // Size of given matrix
    int n = M.size();

    // Top and Down pointers
    int top = 0, down = n - 1;

    // Traverse for all the people
    while (top < down)
    {

        /* If top knows down,
        it can not be a celebrity */
        if (M[top][down] == 1)
        {
            top = top + 1;
        }

        /* If down knowns top,
        it can not be a celebrity */
        else if (M[down][top] == 1)
        {
            down = down - 1;
        }

        /* If both does not know each other,
        both cannot be the celebrity */
        else
        {
            top++;
            down--;
        }
    }

    // Return -1 if no celebrity is found
    if (top > down)
        return -1;

    /* Check if the person pointed
    by top is celebrity */
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;

        // Check if it is not a celebrity
        if (M[top][i] == 1 || M[i][top] == 0)
        {
            return -1;
        }
    }

    // Return the index of celebrity
    return top;
}

int main()
{
    vector<vector<int>> person{{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << "Brute: " << celebrityProblemBrute(person) << endl;
    cout << "Better : " << celebrityProblem(person) << endl;
    cout << "Optimal: " << celebrityProblem(person) << endl;

    return 0;
}