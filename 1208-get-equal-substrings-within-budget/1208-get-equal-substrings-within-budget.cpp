class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sizee= s.length();
        int l =0;
        int r=0;

        int maxLen=0;


        while(r<sizee){
            maxCost-=(abs(s[r]-t[r]));

            while(maxCost<0){
             maxCost+=(abs(s[l]-t[l])); 
             l++;  
            }

            maxLen= max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};