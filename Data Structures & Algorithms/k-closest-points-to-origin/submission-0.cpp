class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>>ans;
       priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>>, greater<pair<int , pair<int,int>>>>pq;
       for(int i = 0; i < n; i++){
        int x = points[i][0];
        int y = points[i][1];

        int dist = x*x + y*y;

        pq.push({dist , {x , y}});

       }
       while(!pq.empty() && k--){
           int dis = pq.top().first;
           int x = pq.top().second.first;
           int y = pq.top().second.second;
           pq.pop();
           
           ans.push_back({x , y});
       }
       return ans;
    }
};
