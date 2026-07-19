class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        int n = intervals.size();
        if(n == 0) return 0;

        sort(intervals.begin(), intervals.end(),
        [](Interval &a, Interval &b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(intervals[0].end);

        for(int i = 1; i < n; i++){

            if(intervals[i].start >= pq.top()){
                pq.pop();
            }

            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};