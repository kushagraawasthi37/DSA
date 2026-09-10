class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size()==1) return intervals;
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int newSt = intervals[0][0];
        int newEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (newEnd < intervals[i][0]) {
                ans.push_back({newSt, newEnd});
                newSt = intervals[i][0];
                newEnd = intervals[i][1];
            } else {
                newEnd = max(intervals[i][1], newEnd);
            }


            if(i== intervals.size()-1)ans.push_back({newSt, newEnd});
        }



        return ans;
    }
};