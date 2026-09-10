class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        int n = intervals.size();
        if(n == 0) return true;

        sort(intervals.begin(), intervals.end(),
        [](Interval &a, Interval &b){
            return a.start < b.start;
        });

        int start = intervals[0].start;
        int end = intervals[0].end;

        for(int i = 1; i < n; i++) {

            if(intervals[i].start >= end) {
                end = intervals[i].end;
            }
            else {
                return false;
            }
        }

        return true;
    }
};