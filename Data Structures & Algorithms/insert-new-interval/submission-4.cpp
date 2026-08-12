class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (end < newInterval[0]) {
                ans.push_back({start, end});
            }
            else if (end >= newInterval[0]&& start <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], end);
            }
            else {
                ans.push_back(newInterval);

                while (i < n) {
                    ans.push_back(intervals[i]);
                    i++;
                }

                return ans;
            }
        }

        ans.push_back(newInterval);

        return ans;
    }
};