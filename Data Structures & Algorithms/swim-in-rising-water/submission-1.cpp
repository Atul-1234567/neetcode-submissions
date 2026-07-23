class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0,0}});

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!pq.empty()){
          int cost = pq.top().first;
          int row = pq.top().second.first;
          int col = pq.top().second.second;
          pq.pop();


            if(row == n-1 && col == n-1)
                return cost;

            for(int i=0;i<4;i++){

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n){

                    int newcost = max(cost, grid[nr][nc]);

                    if(newcost < dist[nr][nc]){

                        dist[nr][nc] = newcost;
                        pq.push({newcost,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};
