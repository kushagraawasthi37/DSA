class Solution {
public:
    int maxDepth(string s) {
        int d=0;
        int ans =0;
        for(auto c:s){
            if(c=='('){
                d++;
                ans= max(ans, d);
            }else if(c==')') d--;
        }

        return ans;
    }
};