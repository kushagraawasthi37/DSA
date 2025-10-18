#include <bits/stdc++.h>
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

    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insertUtil(TrieNode *root, string word, int wordIdx)
    {
        // base case
        if (word.length() == wordIdx)
        {
            root->isTerminal = true;
            return;
        }

        // Assume word will be in CAPS
        int index = word[wordIdx] - 'A';

        TrieNode *child;

        // Present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // Absent
        else
        {
            child = new TrieNode(word[wordIdx]);
            root->children[index] = child;
        }

        insertUtil(child, word, wordIdx + 1);
    }

public:
    void insertWord(string word)
    {
        insertUtil(root, word, 0);
    }

    // Search in Trie

private:
    bool searchUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int idx = word[0] - 'A';
        TrieNode *child;

        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }

        // Absent
        else
        {
            return false;
        }

        // Reccursion
        return searchUtil(child, word.substr(1));
    }

public:
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

public:
    bool removeUtil(TrieNode *root, string word)
    {
        if (!root)
            return false;

        // Base case: end of the word
        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;

                // If no children, node can be deleted

                for (int i = 0; i < 26; ++i)
                {
                    if (root->children[i] != NULL)
                    {
                        return false;
                    }
                } // has children, cannot delete

                return true; // safe to delete
            }
            return false; // word wasn't marked terminal
        }

        int idx = word[0] - 'A';
        TrieNode *child = root->children[idx];

        if (!child)
            return false; // word not found

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild)
        {
            delete child;
            root->children[idx] = NULL;

            // If current node is not terminal and has no children, delete it too
            if (!root->isTerminal)
            {
                for (int i = 0; i < 26; ++i)
                {
                    if (root->children[i] != NULL)
                    {
                        return false;
                    }
                }

                return true; // this node can also be deleted
            }
        }

        return false; // do not delete this node
    }

    void removeWord(string word)
    {
        if (removeUtil(root, word))
            return;

        else
        {
            cout << "Word Not Exist" << endl;
        }
    }
};

int main()
{

    Trie *t = new Trie();
    t->insertWord("ANCD");
    t->insertWord("BNCE");
    t->insertWord("BNCD");

    cout << "Present or Not " << t->searchWord("ANCD") << endl;
    t->removeWord("ANCD");
    cout << "Present or Not " << t->searchWord("ANCD") << endl;

    return 0;
}