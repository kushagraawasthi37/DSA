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
    Node* rightMostChar;
    Node* cursor;

    int deleteKNode(int k) {
        Node* nextNode = cursor->next;
        int deletedCnt = 0;
        while (k-- && cursor != root) {

            if (cursor == rightMostChar)
                rightMostChar = cursor->prev;

            cursor = cursor->prev;
            cursor->next = nullptr;

            deletedCnt++;
        }

        if (nextNode) {
            nextNode->prev = cursor;
            cursor->next = nextNode;
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

        while (m-- && node != root) {
            left += node->val;
            node = node->prev;
        }

        reverse(left.begin(), left.end());

        return left;
    }

    string rightKStep(int k) {
        int m = 10;

        while (k-- && cursor != rightMostChar) {
            cursor = cursor->next;
        }

        Node* node = cursor;
        string right = "";

        while (m-- && node != root) {
            right += node->val;
            node = node->prev;
        }

        reverse(right.begin(), right.end());

        return right;
    }

public:
    TextEditor() {
        root = new Node('|');
        cursor = root;
        rightMostChar = root;
    }

    void addText(string text) {
        Node* nextNode = cursor->next;

        for (auto c : text) {
            Node* curr = new Node(c);
            curr->prev = cursor;
            cursor->next = curr;
            cursor = curr;
        }

        if (nextNode) {
            cursor->next = nextNode;
            nextNode->prev = cursor;
        }

        else
            rightMostChar = cursor;
    }

    int deleteText(int k) { return deleteKNode(k); }

    string cursorLeft(int k) { return leftKStep(k); }

    string cursorRight(int k) { return rightKStep(k); }
};
