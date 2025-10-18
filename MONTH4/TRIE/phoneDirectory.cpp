#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char data;

    // Maximum 26 letter ho skte hai
    TrieNode *children[26];

    // Terminal Node bhi pata hona chahiye
    bool isTerminal;

    // Constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

private:
    void insertUtil(TrieNode *root, string &word, int index)
    {
        if (index == word.length())
        {
            root->isTerminal = true;
            return;
        }

        int idx = word[index] - 'a';
        TrieNode *child;

        // Present
        if (root->children[idx])
        {
            child = root->children[idx];
        }
        else
        {
            child = new TrieNode(word[index]);
            root->children[idx] = child;
        }

        insertUtil(child, word, index + 1);
    }

public:
    void insertWord(string word)
    {
        insertUtil(root, word, 0);
    }

private:
    void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

public:
    vector<vector<string>> getSuggestion(string str)
    {
        vector<vector<string>> output;
        TrieNode *prev = root;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            // check for lastch
            TrieNode *curr = prev->children[lastch - 'a'];

            // If not found
            if (!curr)
                break;

            // found
            else
            {
                vector<string> temp;
                printSuggestion(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie('\0');

    // insert all contact in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        t->insertWord(contactList[i]);
    }

    // Return ans
    return t->getSuggestion(queryStr);
}

int main()
{
    vector<string> contacts = {"code", "coder", "coding", "cat", "cool"};
    string query = "co";

    vector<vector<string>> results = phoneDirectory(contacts, query);

    for (int i = 0; i < results.size(); i++)
    {
        cout << "Suggestions for \"" << query.substr(0, i + 1) << "\": ";
        for (const string &s : results[i])
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
