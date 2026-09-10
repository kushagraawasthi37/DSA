class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int size = intervals.size();

        if (size == 0)
            return {newInterval};

        vector<vector<int>> ans;

        int i = 0;
        while (i < size) {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i++]);
            else
                break;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], intervals[i][0]),
                           max(newInterval[1], intervals[i][1])};
            i++;
        }

        ans.push_back(newInterval);

        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};