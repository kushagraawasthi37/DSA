struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(char c) {
        val = c;
        prev = next = nullptr;
    }
};

class TextEditor {

private:
    Node* root;
    Node* cursor;

    string getLast10() {
        string ans;
        Node* node = cursor;

        for (int i = 0; i < 10 && node != root; i++) {
            ans += node->val;
            node = node->prev;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    int deleteKNode(int k) {
        Node* nextNode = cursor->next;
        int deletedCnt = 0;

        while (k-- && cursor != root) {
            cursor = cursor->prev;
            cursor->next = nullptr;
            deletedCnt++;
        }

        cursor->next = nextNode;
        if (nextNode) {
            nextNode->prev = cursor;
        }

        return deletedCnt;
    }

    string leftKStep(int k) {
        string left = "";

        while (k-- && cursor != root) {
            cursor = cursor->prev;
        }

        Node* node = cursor;
        int m = 10;

        return getLast10();
    }

    string rightKStep(int k) {
        int m = 10;

        while (k-- && cursor->next) {
            cursor = cursor->next;
        }

        return getLast10();
    }

public:
    TextEditor() {
        root = new Node('|');
        cursor = root;
    }

    void addText(string text) {
        Node* nextNode = cursor->next;

        for (auto c : text) {
            Node* curr = new Node(c);
            curr->prev = cursor;
            cursor->next = curr;
            cursor = curr;
        }

        cursor->next = nextNode;

        if (nextNode) {
            nextNode->prev = cursor;
        }
    }

    int deleteText(int k) { return deleteKNode(k); }

    string cursorLeft(int k) { return leftKStep(k); }

    string cursorRight(int k) { return rightKStep(k); }
};
