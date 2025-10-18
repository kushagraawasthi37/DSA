#include <bits/stdc++.h>
using namespace std;

// WITHOUT THE TRIE
//  TC->O(M*N) SC->O(1)
string longestCommonPrefix(vector<string> &arrayOfString, int n)
{

    string ans = "";

    for (int i = 0; i < arrayOfString[0].length(); i++)
    {
        // First string se compare kra rhe hai
        char ch = arrayOfString[0][i];

        bool match = true;
        // for comparing with the rest of string

        for (int j = 0; j < n; j++)
        {
            if (arrayOfString[j].size() < i || ch != arrayOfString[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }

        return ans;
    }
}

// Using trie

class TrieNode
{
public:
    char data;

    // Maximum 26 letter ho skte hai
    TrieNode *children[26];

    int childCount;
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
        childCount = 0;
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

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        TrieNode *child;

        // Present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // Absent
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(root, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // Age badh jao
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefUsingTrie(TrieNode *root, vector<string> &vec)
{
    Trie *t = new Trie('\0');
    int n = vec.size();

    // Step 1 ADD ALL STRING TO TRIE
    for (int i = 0; i < n; i++)
    {
        t->insertWord(vec[i]);
    }

    string first = vec[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
    // STEP 2 TILL WE HAVE NODE HAVING ONLY ONE CHILD COUNT THEN IT IS CONSIDERED  ELSE BREAK
}
int main()
{
    return 0;
}