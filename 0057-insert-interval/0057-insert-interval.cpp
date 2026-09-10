class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int size = intervals.size();

        if (size == 0)
            return {newInterval};

        vector<vector<int>> ans;

        if (newInterval[1] < intervals[0][0]) {
            ans.push_back(newInterval);
            for (auto ele : intervals)
                ans.push_back(ele);
            return ans;
        }

        int i = 0;
        while (i < size) {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i++]);
            else
                break;
        }

        if (i == size) {
            ans.push_back(newInterval);
            return ans;
        }
        int intSt;
        int intEnd;

        
        if (newInterval[1] < intervals[i][0]) {
            ans.push_back({newInterval});
            intSt = intervals[i][0];
            intEnd = intervals[i][1];
        } else {
            intSt = min(intervals[i][0], newInterval[0]);
            intEnd = max(intervals[i][1], newInterval[1]);
        }

        for (; i < size; i++) {
            if (intEnd < intervals[i][0]) {
                ans.push_back({intSt, intEnd});
                intSt = intervals[i][0];
                intEnd = intervals[i][1];
            } else {
                intEnd = max(intervals[i][1], intEnd);
            }

            if (i == size - 1) {
                ans.push_back({intSt, intEnd});
            }
        }

        return ans;
    }
};