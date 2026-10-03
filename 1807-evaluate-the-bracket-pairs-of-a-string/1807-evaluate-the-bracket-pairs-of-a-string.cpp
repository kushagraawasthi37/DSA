class Solution {
public:

    string findValue(const string &charKey,
                     unordered_map<string, string> &umap) {

        auto it = umap.find(charKey);

        if (it != umap.end()) {
            return it->second;
        }

        return "?";
    }

    string evaluate(string s, vector<vector<string>>& knowledge) {

        string output = "";
        int n = s.length();

        bool foundKey = false;
        string charKey = "";

        unordered_map<string, string> umap;

        // Store all knowledge pairs in the hash map
        for (auto it : knowledge) {
            umap[it[0]] = it[1];
        }

        // Process the string
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                foundKey = true;
                continue;
            }

            if (foundKey) {

                if (s[i] == ')') {

                    output += findValue(charKey, umap);

                    foundKey = false;
                    charKey = "";

                } else {

                    charKey += s[i];
                }

            } else {

                output += s[i];
            }
        }

        return output;
    }
};