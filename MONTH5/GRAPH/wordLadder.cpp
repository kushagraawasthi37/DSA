#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
        unordered_map<string, int> m;

        // Stroring all the wordlist into hashtable
        for (int i = 0; i < wordList.size(); i++)
        {
            m[wordList[i]]++;
        }

        queue<pair<string, int>> q;
        q.push({startWord, 1});
        // Remove start word from the map
        m.erase(startWord);

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            string word = front.first;
            int step = front.second;

            if (word == targetWord)
                return step;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (m.find(word) != m.end())
                    {
                        q.push({word, step + 1});
                        m.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
int main()
{

    string startWord = "der", targetWord = "dfs";
    vector<string> wordList =
        {"des", "der", "dfr", "dgt", "dfs"};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to determine number of
    steps to reach from start ward to target word */
    int ans =
        sol.wordLadderLength(startWord, targetWord, wordList);

    // Output
    cout << "Word ladder length is: " << ans;

    return 0;
}