class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();

        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int mini = INT_MAX;

            for (int j = 0; j < n; j++) {
                if (queries[i] >= intervals[j][0] && queries[i] <= intervals[j][1]) {
                    int length = intervals[j][1] - intervals[j][0] + 1;
                    mini = min(mini, length);
                }
            }

            if (mini == INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(mini);
        }

        return ans;
    }
};