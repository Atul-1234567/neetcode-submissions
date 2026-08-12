class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        while (i < n) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Current interval is completely before newInterval
            if (end < newInterval[0]) {
                ans.push_back({start, end});
            }

            // Current interval is completely after newInterval
            else if (start > newInterval[1]) {
                ans.push_back(newInterval);

                while (i < n) {
                    ans.push_back(intervals[i]);
                    i++;
                }

                return ans;
            }

            // Overlapping
            else {
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], end);
            }

            i++;
        }

        ans.push_back(newInterval);

        return ans;
    }
};