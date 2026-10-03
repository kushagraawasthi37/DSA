class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int> st;
        vector<int> pairOf(n);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);

            else if(s[i] == ')')
            {
                int j = st.top();
                st.pop();

                pairOf[i] = j;
                pairOf[j] = i;
            }
        }

        string res = "";

        for(int i = 0, dir = 1; i < n; i += dir)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                i = pairOf[i];

                dir = -dir;
            }
            else
            {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};