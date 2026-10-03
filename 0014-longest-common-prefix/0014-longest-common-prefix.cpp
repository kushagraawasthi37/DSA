struct Node {
    bool isEnd = false;
    Node* link[26] = {nullptr};

    Node* get(int key) { return link[key]; }

    bool contain(int key) { return link[key] != nullptr; }

    void set(int key) { link[key] = new Node(); }

    void setTerminal() { this->isEnd = true; }

    bool isTerminal() { return this->isEnd; }
};

class Solution {
    Node* root = new Node();

    void insertWord(string& word) {
        Node* node = root;

        for (auto ch : word) {
            if (!node->contain(ch - 'a')) {
                node->set(ch - 'a');
            }

            node = node->get(ch - 'a');
        }

        node->setTerminal();
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        Node* node = root;
        string ans;

        for (auto& word : strs) {
            if (word.length() == 0)
                return "";
            insertWord(word);
        }

        while (1) {

            if (node->isTerminal())
                break;
            int flag = 0;
            for (int i = 0; i < 26; i++) {
                if (node->contain(i) && flag == 0) {
                    flag = 1;
                    ans.push_back('a' + i);
                } else if (node->contain(i)) {
                    flag++;
                    break;
                }
            }

            if (flag == 0) {
                break;
            }

            if (flag > 1) {
                ans.pop_back();
                break;
            }

            node = node->get(ans.back() - 'a');
        }

        return ans;
    }
};