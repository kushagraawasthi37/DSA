
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string startWord, string endWord,
                                         vector<string> &wordList)
    {
        unordered_map<string, int> m;

        // Stroring all the wordlist into hashtable
        for (int i = 0; i < wordList.size(); i++)
        {
            m[wordList[i]]++;
        }

        queue<vector<string>> q;
        vector<vector<string>> res;
        q.push({startWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(startWord);
        // Remove start word from the map
        m.erase(startWord);
        int level = 0;

        // Traverse queue until removed
        while (!q.empty())
        {
            auto vec = q.front();
            q.pop();

            // Check is it the start of new level or not
            if (vec.size() > level)
            {
                level++;

                // Remove all word that are removed on the previous level
                for (auto it : usedOnLevel)
                {
                    m.erase(it);
                }

                // Purane level word ko clear kardo
                usedOnLevel.clear();
            }

            // Last word jo add kiya hai use change karo
            string word = vec.back();

            // Agar wo word target ke equal ho to
            if (word == endWord)
            {
                if (res.size() == 0)
                {
                    res.push_back(vec);
                }
                else
                {
                    if (res[0].size() == vec.size())
                    {
                        res.push_back(vec);
                    }
                }
            }

            // Modify the word
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (m.find(word) != m.end())
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return res;
    }
};

int main()
{

    string beginWord = "der", endWord = "dfs";
    vector<string> wordList =
        {"des", "der", "dfr", "dgt", "dfs"};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to determine number of
    steps to reach from start ward to target word */
    vector<vector<string>> ans =
        sol.findSequences(beginWord, endWord, wordList);

    // Output
    cout << "The different sequences are:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}