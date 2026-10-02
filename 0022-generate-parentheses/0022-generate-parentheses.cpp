class Solution {
    void solve(int open_cnt, int close_cnt, string& temp, vector<string>& res,
               int n) {

        if (temp.size() == 2 * n) {
            res.push_back(temp);
            return;
        }

        if (open_cnt  < n) {
            temp.push_back('(');
            solve(open_cnt + 1, close_cnt, temp, res, n);
            temp.pop_back();
        }

        if (close_cnt < open_cnt) {
            temp.push_back(')');
            solve(open_cnt, close_cnt + 1, temp, res, n);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";

        solve(0, 0, temp, res, n);

        return res;
    }
};