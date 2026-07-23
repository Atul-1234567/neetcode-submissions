class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int cnt = 0;

        for(int i = 1;  i < n; i++){
            if(intervals[i][0] < end){
                cnt++;
                end = min(end , intervals[i][1]);
            }
            else if(intervals[i][0] >= end){
                start = intervals[i][0];
                 end = intervals[i][1];           }
        }
        return cnt;
    }
};
